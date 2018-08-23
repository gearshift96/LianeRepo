// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TKShield.generated.h"

class USphereComponent;
class USoundCue;
class UParticleSystem;
class UMaterialInterface;


UCLASS()
class LIANEGAME_API ATKShield : public AActor
{
	GENERATED_BODY()
	
	//UFUNCTION()
	//void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

public:	
	ATKShield();

	UPROPERTY(EditAnywhere)
	UMaterialInterface* ShieldMaterial;

	/*UPROPERTY(EditAnywhere, Category = "Timeline")
	class UCurveFloat* fCurve;
	
	UPROPERTY(EditAnywhere)
	UParticleSystem* ShieldImpactParticle;

	UTimelineComponent* ShieldTimeline;

	FOnTimelineFloat InterpFunction;

	FOnTimelineEvent TimelineUpdated;

	UFUNCTION()
	void TimelineFloatReturn(float value);

	UFUNCTION()
	void OnTimelineUpdate();
	*/
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* ShieldMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USphereComponent* ShieldCollision;
	
};
