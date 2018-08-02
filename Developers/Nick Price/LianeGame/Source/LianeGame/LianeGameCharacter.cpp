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
#include "Animation/AnimInstance.h"
#include "HealthComponent.h"
#include "Net/UnrealNetwork.h"

#define OUT
//////////////////////////////////////////////////////////////////////////
// ALianeGameCharacter
ALianeGameCharacter::ALianeGameCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	//set our telekinesis variables
	ThrowStrength = 250000.0f;
	Reach = 750.f;

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

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 100.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arms

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));

	ZoomedFOV = 60.0f;
	ZoomInterpSpeed = 20;

	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp"));


	//WeaponAttachSocketName = "WeaponSocket";
}

void ALianeGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	DefaultFOV = FollowCamera->FieldOfView;
	HealthComp->OnHealthChanged.AddDynamic(this, &ALianeGameCharacter::OnHealthChanged);
}

void ALianeGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetPhysicsHandleLocation();
	//FaceTKObject();

	float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV;
	float NewFOV = FMath::FInterpTo(FollowCamera->FieldOfView, TargetFOV, DeltaTime, ZoomInterpSpeed);

	FollowCamera->SetFieldOfView(NewFOV);
}

void ALianeGameCharacter::MoveForward(float v)
{
	if (v != 0.0f)
	{
		// Find out which way is "forward" and record that the player wants to move that way.
		FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, v);
	}
}

void ALianeGameCharacter::MoveLeftRight(float h)
{
	if (h != 0.0f)
	{
		// Find out which way is "right" and record that the player wants to move that way.
		FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, h);
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void ALianeGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);


	PlayerInputComponent->BindAction("ZoomAim", IE_Pressed, this, &ALianeGameCharacter::BeginZoom);
	PlayerInputComponent->BindAction("ZoomAim", IE_Released, this, &ALianeGameCharacter::EndZoom);

	//Axis bindings
	PlayerInputComponent->BindAxis("LookUp", this, &ALianeGameCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ALianeGameCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAxis("MoveForward", this, &ALianeGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeftRight", this, &ALianeGameCharacter::MoveLeftRight);

	//Telekinesis key bindings
	PlayerInputComponent->BindAction("TKGrab", IE_Pressed, this, &ALianeGameCharacter::Grab);
	PlayerInputComponent->BindAction("TKGrab", IE_Released, this, &ALianeGameCharacter::Release);

	PlayerInputComponent->BindAction("TKThrow", IE_Pressed, this, &ALianeGameCharacter::TKThrow);

	PlayerInputComponent->BindAction("TKShield", IE_Pressed, this, &ALianeGameCharacter::TKShield);

	PlayerInputComponent->BindAction("TKHeal", IE_Pressed, this, &ALianeGameCharacter::TKHeal);
}

void ALianeGameCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ALianeGameCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ALianeGameCharacter::BeginZoom()
{
	bWantsToZoom = true;
}

void ALianeGameCharacter::EndZoom()
{
	bWantsToZoom = false;
}
void ALianeGameCharacter::OnHealthChanged(UHealthComponent * OwningHealthComp, float Health, float HealthDelta, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (Health <= 0.0f && !bDied)
	{
		// Die!
		bDied = true;

		GetMovementComponent()->StopMovementImmediately();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		DetachFromControllerPendingDestroy();

		SetLifeSpan(10.0f);
	}
}

void ALianeGameCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(ASCharacter, CurrentWeapon);
	DOREPLIFETIME(ALianeGameCharacter, bDied);
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
		FaceTKObject();
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
			Reach = 750.f;	 //Reset the telekinesis reach
		}
}

void ALianeGameCharacter::TKThrow()
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

			auto Direction = PlayerLoc - GrabbedComponentLoc;
			//FRotator GrabbedComponentRot = FRotationMatrix::MakeFromX(-Direction).Rotator();

			auto GrabbedComponentRot = UKismetMathLibrary::FindLookAtRotation(FVector(0, PlayerLoc.Y, 0), FVector(0, GrabbedComponentLoc.Y,0));
			GetCapsuleComponent()->SetWorldRotation(GrabbedComponentRot);
		}
}

void ALianeGameCharacter::TKHeal()
{

}

void ALianeGameCharacter::TKShield()
{

}

void ALianeGameCharacter::SetPhysicsHandleLocation()
{
	auto FCLoc = FollowCamera->GetComponentLocation();
	auto FCFVec = FollowCamera->GetForwardVector() * Reach;
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
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * 800;
}
