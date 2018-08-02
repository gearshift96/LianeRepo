// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TKShield.generated.h"

class USHealthComponent;
class USphereComponent;
class USoundCue;

UCLASS()
class LIANEGAME_API ATKShield : public AActor
{
	GENERATED_BODY()
	
public:	
	ATKShield();

protected:
	virtual void BeginPlay() override;

	/*UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USphereComponent* SphereComp;
	*/
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
