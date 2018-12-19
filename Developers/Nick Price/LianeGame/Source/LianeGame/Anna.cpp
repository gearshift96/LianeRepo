#include "Anna.h"
#include "LianeGameCharacter.h"
#include "HealthComponent.h"
#include "TimerManager.h"
#include "TKShield.h"
#include "DrawDebugHelpers.h"

#define OUT
//////////////////////////////////////////////////////////////////////////
// ALianeGameCharacter
AAnna::AAnna()
{
	PrimaryActorTick.bCanEverTick = true;

	//set our telekinesis variables
	ThrowStrength = 250000.0f;
	Reach = 750.f;
	bCanUseTelekinesis = true;

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

	ShieldSpawner = CreateDefaultSubobject<USceneComponent>(TEXT("ShieldSpawner"));
}

AAnna::~AAnna()
{
}


void AAnna::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(RechargeTimerHandle, this, &AAnna::RechargeShield, 1.0f, true);

}

void AAnna::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetPhysicsHandleLocation();
	//FaceTKObject();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AAnna::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	//Telekinesis key bindings
	PlayerInputComponent->BindAction("TKGrab", IE_Pressed, this, &AAnna::Grab);
	PlayerInputComponent->BindAction("TKGrab", IE_Released, this, &AAnna::Release);

	PlayerInputComponent->BindAction("TKThrow", IE_Pressed, this, &AAnna::TKThrow);

	PlayerInputComponent->BindAction("TKShield", IE_Pressed, this, &AAnna::TKShieldF);

	PlayerInputComponent->BindAction("Heal", IE_Pressed, this, &AAnna::TKHeal);
}

void AAnna::TKHeal()
{
	if (!bCanUseTelekinesis) { return; }
	GLog->Log("Healing work in Progress!");
}

void AAnna::TKShieldF()
{
	UE_LOG(LogTemp, Warning, TEXT("Shield Work in progress!"));
	if (bCanUseShield)
	{
		if (bIsReady())
		{
			UWorld* const World = GetWorld();
			//play sound here
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.Owner = this;
			SpawnInfo.Instigator = Instigator;
			SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			if (World)
			{
				if (TKShieldBlueprint != nullptr)
				{
					bCanUseShield = false;
					bCanUseTelekinesis = false;
					TKShield = World->SpawnActor<ATKShield>(TKShieldBlueprint, ShieldSpawner->GetComponentLocation(), ShieldSpawner->GetComponentRotation(), SpawnInfo);
					if (bDebugTelekinesis)
					{
						DrawDebugSphere(GetWorld(), ShieldSpawner->GetComponentLocation(), 200, 26, FColor::Emerald, true, 999, 0, 2);
					}
					TKShield->AttachToComponent(ShieldSpawner, FAttachmentTransformRules::SnapToTargetIncludingScale, NAME_None);
					UE_LOG(LogTemp, Log, TEXT("Shield is Attached!"))
					GetCharacterMovement()->MaxWalkSpeed = 200.f;
					GetWorldTimerManager().SetTimer(ShieldTimerHandle, this, &AAnna::ActivateShield, 1.0f, true);
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Shield is missing please attach a shield!"));
					return;
				}
			}
		}
	}
}

void AAnna::ActivateShield()
{
	UE_LOG(LogTemp, Warning, TEXT("Shield is active!"));
	--ShieldLifetime;
	if (ShieldLifetime <= 0)
	{
		GetWorldTimerManager().ClearTimer(ShieldTimerHandle);
		CountdownHasFinished();
	}
}

void AAnna::RechargeShield()
{
	UE_LOG(LogTemp, Warning, TEXT("Shield is cooling down!"));
	--ShieldCooldown;

	if (ShieldCooldown <= 0)
	{
		GetWorldTimerManager().ClearTimer(RechargeTimerHandle);
		CooldownHasFinished();
	}
}

bool AAnna::bIsReady()
{
	return ShieldCooldown <= 0;
}

void AAnna::CountdownHasFinished_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Countdown has finished!"));
	bCanUseTelekinesis = true;
	ShieldCooldown = 30;
	GLog->Log("Shield is Destroyed!");
	TKShield->Destroy();
	GetWorldTimerManager().SetTimer(RechargeTimerHandle, this, &AAnna::RechargeShield, 1.0f, true);
}

void AAnna::CooldownHasFinished_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Cooldown has finished!"));
	bCanUseShield = true;
	ShieldLifetime = 5;
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
}

/*Telekinesis Logic*/

void AAnna::Grab()
{
	if (!bCanUseTelekinesis) { return; }
	/// LINE TRACE and see if we reach any actors with physics body collision channel set
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent(); // gets an actor with physics 
	auto ActorHit = HitResult.GetActor();

	/// If we hit something then attach a physics handle
	if (ActorHit)
	{

		if (!PhysicsHandle) { return; }
		PhysicsHandle->GrabComponentAtLocation(
			ComponentToGrab,
			NAME_None, // no bones needed
			ComponentToGrab->GetOwner()->GetActorLocation()
		);
		ComponentToGrab->SetEnableGravity(false);
		FaceTKObject();
	}
}

void AAnna::Release()
{
	if (!PhysicsHandle) { return; }
	if (!bCanUseTelekinesis) { return; }
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

void AAnna::TKThrow()
{
	if (!PhysicsHandle) { return; }
	if (!bCanUseTelekinesis) { return; }
	if (PhysicsHandle->GetGrabbedComponent() != nullptr)
	{
		FVector TKImpulse = FollowCamera->GetForwardVector() * ThrowStrength;
		PhysicsHandle->GrabbedComponent->AddImpulse(TKImpulse, NAME_None, false);
		Release();
		//add camera shake effect
		if (bDebugTelekinesis)
		{
			DrawDebugCrosshairs(GetWorld(), TKImpulse, FRotator(0, 0, 0), 500.f, FColor::White, true, 999, 0);
		}
	}
	}

void AAnna::FaceTKObject()
{
	if (!bCanUseTelekinesis) { return; }
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

		auto GrabbedComponentRot = UKismetMathLibrary::FindLookAtRotation(FVector(0, PlayerLoc.Y, 0), FVector(0, GrabbedComponentLoc.Y, 0));
		GetCapsuleComponent()->SetWorldRotation(GrabbedComponentRot);
	}
}

void AAnna::SetPhysicsHandleLocation()
{
	auto FCLoc = FollowCamera->GetComponentLocation();
	auto FCFVec = FollowCamera->GetForwardVector() * Reach;
	auto FCTarLoc = FCLoc + FCFVec;

	if (bDebugTelekinesis)
	{
		DrawDebugDirectionalArrow(GetWorld(), FCFVec, FCFVec + 750.f, 120.f, FColor::Magenta, true, 999, 0, 5.f);
	}
	if (!PhysicsHandle)
	{UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName()) return; }
	// if the physics handle is attached
	if (PhysicsHandle->GrabbedComponent)
	{
		// move the object that we're holding
		PhysicsHandle->SetTargetLocation(FCTarLoc);
	}
}

const FHitResult AAnna::GetFirstPhysicsBodyInReach()
{
	/// Line-trace (AKA ray-cast) out to reach distance
	FHitResult HitResult;
	if (bDebugTelekinesis)
	{
		DrawDebugLine(GetWorld(), GetTKReachLineStart() ,GetTKReachLineEnd(), FColor::Cyan, false, 10, 0, 10);
	}
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

FVector AAnna::GetTKReachLineStart()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;

	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	return PlayerViewPointLocation;
}

FVector AAnna::GetTKReachLineEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
	);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}
