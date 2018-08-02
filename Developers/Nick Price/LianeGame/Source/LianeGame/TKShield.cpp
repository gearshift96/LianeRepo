// Fill out your copyright notice in the Description page of Project Settings.

#include "TKShield.h"
#include "DrawDebugHelpers.h"
#include "HealthComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Sound/SoundCue.h"


static int32 DebugTKShieldDrawing = 0;
FAutoConsoleVariableRef CVARDebugTKShieldDrawing(
	TEXT("ProjectLiane.DebugTKShield"),
	DebugTKShieldDrawing,
	TEXT("Draw Debug Lines for Telekinesis Shield"),
	ECVF_Cheat);

ATKShield::ATKShield()
{
	PrimaryActorTick.bCanEverTick = true;
	/*
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("ShieldCollision"));
	SphereComp->SetSphereRadius(190);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Block);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = SphereComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldMesh"));
	MeshComp->SetCanEverAffectNavigation(true);
	MeshComp->SetupAttachment(RootComponent);
	*/
}

// Called when the game starts or when spawned
void ATKShield::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATKShield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


