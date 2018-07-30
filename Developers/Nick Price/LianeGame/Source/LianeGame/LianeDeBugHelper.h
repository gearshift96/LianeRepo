// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LianeDeBugHelper.generated.h"

class UBoxComponent;
class UTextRenderComponent;

//------------------------------------------------------------
// usage:
// add to class declaration
// AQLDebugHelper* DebugHelper;
//
// add to BeginPlay()
// DebugHelper = GetWorld()->SpawnActor<AQLDebugHelper>(AQLDebugHelper::StaticClass());
// DebugHelper->AttachToComponent(GetCapsuleComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale);
// DebugHelper->SetActorRelativeLocation(FVector(200.0f, 0.0f, 0.0f));
//------------------------------------------------------------
UCLASS()
class LIANEGAME_API ALianeDeBugHelper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALianeDeBugHelper();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UStaticMeshComponent* XAxis;
	UStaticMeshComponent* YAxis;
	UStaticMeshComponent* ZAxis;
	UTextRenderComponent* XAxisLabel;
	UTextRenderComponent* YAxisLabel;
	UTextRenderComponent* ZAxisLabel;
	UBoxComponent* BoxComponent;
	
};
