// Fill out your copyright notice in the Description page of Project Settings.

#include "TKShield.h"
#include "DrawDebugHelpers.h"
#include "HealthComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Sound/SoundCue.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"


static int32 DebugTKShieldDrawing = 0;
FAutoConsoleVariableRef CVARDebugTKShieldDrawing(
	TEXT("ProjectLiane.DebugTKShield"),
	DebugTKShieldDrawing,
	TEXT("Draw Debug Lines for Telekinesis Shield"),
	ECVF_Cheat);

ATKShield::ATKShield()
{
	PrimaryActorTick.bCanEverTick = true;
	
	ShieldCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ShieldCollision"));
	ShieldCollision->SetSphereRadius(190);
	ShieldCollision->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	ShieldCollision->SetCollisionResponseToAllChannels(ECR_Block);

	//Custom trace channels
	ShieldCollision->SetCollisionResponseToChannel(ECC_GameTraceChannel1, ECR_Ignore);//Player
	ShieldCollision->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Ignore);//Floor
	ShieldCollision->SetCollisionResponseToChannel(ECC_GameTraceChannel3, ECR_Block);//Shield 


	RootComponent = ShieldCollision;

	ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldMesh"));
	ShieldMesh->SetCanEverAffectNavigation(true);
	ShieldMesh->SetupAttachment(RootComponent);

	//ShieldTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Animate"));

	//InterpFunction.BindUFunction(this, FName("TimelineFloatReturn"));
	//TimelineUpdated.BindUFunction(this, FName("OnTimelineUpdate"));
}

void ATKShield::BeginPlay()
{
	Super::BeginPlay();

	/*if (fCurve)
	{
		ShieldTimeline->AddInterpFloat(fCurve, InterpFunction, FName{ TEXT("Value") });

		ShieldTimeline->SetTimelinePostUpdateFunc(TimelineUpdated);

		ShieldTimeline->SetLooping(false);
		ShieldTimeline->SetIgnoreTimeDilation(true);
	}*/
}

/*
void ATKShield::TimelineFloatReturn(float value)
{

}

void ATKShield::OnTimelineUpdate()
{
	if (ShieldTimeline->GetPlaybackPosition() == 0.0f)
	{
		GLog->Log("PlayFromStart");
		ShieldTimeline->PlayFromStart();
	}
}

void ATKShield::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	
	UMaterialInstanceDynamic* DynMaterial = UMaterialInstanceDynamic::Create(ShieldMaterial, this);

	DynMaterial->SetVectorParameterValue("Position", Hit.ImpactPoint);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ShieldImpactParticle, Hit.ImpactPoint, Hit.ImpactNormal.X);

	//DynMaterial->SetScalarParameterValue("Radius", value);

	auto Impulse = FMath::GetReflectionVector(OtherComponent->GetComponentVelocity, Hit.ImpactNormal);
	OtherComponent->AddImpulseAtLocation(Impulse * -20000.0f, Hit.ImpactPoint);
}
*/


