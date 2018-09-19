#include "Anna.h"
#include "LianeGameCharacter.h"
#include "HealthComponent.h"
#include "TimerManager.h"
#include "TKShield.h"

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
	GetCharacterMovement()->MaxWalkSpeed = 400.f;

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

	ShieldSpawner = CreateDefaultSubobject<USceneComponent>(TEXT("ShieldSpawner"));

	//WeaponAttachSocketName = "WeaponSocket";
}

void AAnna::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(RechargeTimerHandle, this, &AAnna::RechargeShield, 1.0f, true);
	DefaultFOV = FollowCamera->FieldOfView;
	HealthComp->OnHealthChanged.AddDynamic(this, &AAnna::OnHealthChanged);
}

void AAnna::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetPhysicsHandleLocation();
	//FaceTKObject();

	float TargetFOV = bWantsToZoom ? ZoomedFOV : DefaultFOV;
	float NewFOV = FMath::FInterpTo(FollowCamera->FieldOfView, TargetFOV, DeltaTime, ZoomInterpSpeed);

	FollowCamera->SetFieldOfView(NewFOV);
}

void AAnna::MoveForward(float v)
{
	if (v != 0.0f)
	{
		// Find out which way is "forward" and record that the player wants to move that way.
		FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, v);
	}
}

void AAnna::MoveLeftRight(float h)
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

void AAnna::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("ZoomAim", IE_Pressed, this, &AAnna::BeginZoom);
	PlayerInputComponent->BindAction("ZoomAim", IE_Released, this, &AAnna::EndZoom);

	//Axis bindings
	PlayerInputComponent->BindAxis("LookUp", this, &AAnna::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &AAnna::AddControllerYawInput);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAnna::MoveForward);
	PlayerInputComponent->BindAxis("MoveLeftRight", this, &AAnna::MoveLeftRight);

	//Telekinesis key bindings
	PlayerInputComponent->BindAction("TKGrab", IE_Pressed, this, &AAnna::Grab);
	PlayerInputComponent->BindAction("TKGrab", IE_Released, this, &AAnna::Release);

	PlayerInputComponent->BindAction("TKThrow", IE_Pressed, this, &AAnna::TKThrow);

	PlayerInputComponent->BindAction("TKShield", IE_Pressed, this, &AAnna::TKShield);

	PlayerInputComponent->BindAction("TKHeal", IE_Pressed, this, &AAnna::TKHeal);
}

void AAnna::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AAnna::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AAnna::BeginZoom()
{
	bWantsToZoom = true;
}

void AAnna::EndZoom()
{
	bWantsToZoom = false;
}

void AAnna::OnHealthChanged(UHealthComponent * OwningHealthComp, float Health, float HealthDelta, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
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

void AAnna::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(ALianeGameCharacter, CurrentWeapon);
	DOREPLIFETIME(AAnna, bDied);
}

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

void AAnna::TKHeal()
{
	if (!bCanUseTelekinesis) { return; }
	GLog->Log("Healing work in Progress!");
}

void AAnna::TKShield()
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
				if (ShieldBlueprint != nullptr)
				{
					bCanUseShield = false;
					bCanUseTelekinesis = false;
					Shield = World->SpawnActor<ATKShield>(ShieldBlueprint, ShieldSpawner->GetComponentLocation(), ShieldSpawner->GetComponentRotation(), SpawnInfo);
					Shield->AttachToComponent(ShieldSpawner, FAttachmentTransformRules::SnapToTargetIncludingScale, NAME_None);
					UE_LOG(LogTemp, Warning, TEXT("Shield is Attached!"));
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


void AAnna::SetPhysicsHandleLocation()
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

const FHitResult AAnna::GetFirstPhysicsBodyInReach()
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
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * 800;
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
	Shield->Destroy();
	GetWorldTimerManager().SetTimer(RechargeTimerHandle, this, &AAnna::RechargeShield, 1.0f, true);
}

void AAnna::CooldownHasFinished_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Cooldown has finished!"));
	bCanUseShield = true;
	ShieldLifetime = 5;
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
}

