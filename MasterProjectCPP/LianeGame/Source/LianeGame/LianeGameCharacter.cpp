// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LianeGameCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#define OUT
//////////////////////////////////////////////////////////////////////////
// ALianeGameCharacter

ALianeGameCharacter::ALianeGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	//set our telekinesis variables
	TK_Reach = 750.0f;
	PullDirection = 10500000.0f;
	ThrowStrength = 25000000.0f;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arms

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));
}

void ALianeGameCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ALianeGameCharacter::SetPhysicsHandleLocation()
{
	auto FCLoc = FollowCamera->GetComponentLocation();
	auto FCFVec = FollowCamera->GetForwardVector() * TK_Reach;
	auto FCTarLoc = FCLoc + FCFVec;

	if (!PhysicsHandle) { return; }
	// if the physics handle is attached
	if (PhysicsHandle->GrabbedComponent)
	{
		// move the object that we're holding
		PhysicsHandle->SetTargetLocation(FCTarLoc);
	}

	if (PhysicsHandle == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName())
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ALianeGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ALianeGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALianeGameCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ALianeGameCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ALianeGameCharacter::LookUpAtRate);

	//Telekinesis key bindings
	PlayerInputComponent->BindAction("Grab", IE_Pressed, this, &ALianeGameCharacter::Grab);
	PlayerInputComponent->BindAction("Grab", IE_Released, this, &ALianeGameCharacter::Release);

	PlayerInputComponent->BindAction("Throw", IE_Pressed, this, &ALianeGameCharacter::Throw);

}

void ALianeGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetPhysicsHandleLocation();
	FaceTKObject();
}

void ALianeGameCharacter::Grab()
{
	/// LINE TRACE and see if we reach any actors with physics body collision channel set
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent(); // gets an actor with physics 
	auto ActorHit = HitResult.GetActor();

	/// If we hit something then attach a physics handle
	if (ActorHit)
	{
		if (!PhysicsHandle) { return; }
		PhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None, // no bones needed
			ComponentToGrab->GetOwner()->GetActorLocation(),
			true // allow rotation
		);
		ComponentToGrab->SetEnableGravity(false);
		GetCharacterMovement()->MaxWalkSpeed = 0.f;
	}
}

void ALianeGameCharacter::Release()
{
	if (!PhysicsHandle) { return; }
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentGrabbed = HitResult.GetComponent(); // gets an actor with physics 
	auto ActorHit = HitResult.GetActor();

	/// If we hit something then attach a physics handle
	if (ActorHit)
	{
		PhysicsHandle->ReleaseComponent();
		ComponentGrabbed->SetEnableGravity(true);
		GetCharacterMovement()->MaxWalkSpeed = 600.f;
	}
}

void ALianeGameCharacter::Throw()
{
	if (!PhysicsHandle) { return; }
	if (PhysicsHandle->GetGrabbedComponent() != nullptr)
	{
		FVector TKImpulse = FollowCamera->GetForwardVector() * ThrowStrength;
		PhysicsHandle->GrabbedComponent->AddImpulse(TKImpulse, NAME_None, false);
		Release();
		//add camera shake effect
	}
}

void ALianeGameCharacter::FaceTKObject()
{
	/// LINE TRACE and see if we reach any actors with physics body collision channel set
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto GrabbedComponent = HitResult.GetComponent(); // gets an actor with physics 
	auto ActorHit = HitResult.GetActor();

	/// If we hit something then attach a physics handle
	if (ActorHit)
	{
		auto PlayerLoc = this->GetActorLocation();
		auto GrabbedComponentLoc = GrabbedComponent->GetComponentLocation();
		auto GrabbedComponentRot = UKismetMathLibrary::FindLookAtRotation(FVector(0, 0, PlayerLoc.Z), FVector(0, 0, GrabbedComponentLoc.Z));
		//GetCapsuleComponent()->SetWorldRotation(GrabbedComponentRot);
	}
}

void ALianeGameCharacter::MoveActor()
{
	
}

void ALianeGameCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ALianeGameCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ALianeGameCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ALianeGameCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

const FHitResult ALianeGameCharacter::GetFirstPhysicsBodyInReach()
{
	/// Line-trace (AKA ray-cast) out to reach distance
	FHitResult HitResult;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		GetTKReachLineStart(),
		GetTKReachLineEnd(),
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	return HitResult;
}

FVector ALianeGameCharacter::GetTKReachLineStart()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	return PlayerViewPointLocation;
}

FVector ALianeGameCharacter::GetTKReachLineEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * TK_Reach;
}