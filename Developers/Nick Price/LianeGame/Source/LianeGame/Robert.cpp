// Fill out your copyright notice in the Description page of Project Settings.

#include "Robert.h"
#include "Projectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

ARobert::ARobert()
{
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComp"));
}

ARobert::~ARobert()
{

}

void ARobert::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	HealthComp->OnHealthChanged.AddDynamic(this, &ARobert::OnHealthChanged);
}

//////////////////////////////////////////////////////////////////////////
// Input

void ARobert::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Heal", IE_Pressed, this, &ARobert::Heal);
}

void ARobert::OnHealthChanged(UHealthComponent * OwningHealthComp, float Health, float HealthDelta, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
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

void ARobert::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(ALianeGameCharacter, CurrentWeapon);
	DOREPLIFETIME(ARobert, bDied);
}

void ARobert::Heal()
{
	GLog->Log("Healing work in Progress!");
}