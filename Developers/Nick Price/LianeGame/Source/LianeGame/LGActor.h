// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LGGameInstance.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "LGActor.generated.h"

UCLASS()
class LIANEGAME_API ALGActor : public AActor
{
	GENERATED_BODY()
	
public:
	ALGActor();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void SetLGOwner(AActor* LGOwner_ext);
	virtual void UnSetLGOwner();
	AActor* GetLGOwner();

	void PlaySoundComponent(const FName& SoundName);
	void PlaySoundFireAndForget(const FName& SoundName);

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box component")
	//UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Property")
	UStaticMeshComponent* StaticMeshComponent;

	UStaticMeshComponent*& GetStaticMeshComponent();
protected:
	AActor* LGOwner;
	USoundAttenuation* SoundNoAttenuation;
	USoundAttenuation* SoundAttenuation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Property")
	TMap<FName, TAssetPtr<USoundWave>> SoundComponentAssetList;

	TMap<FName, UAudioComponent*> SoundComponentList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Property")
	TMap<FName, TAssetPtr<USoundWave>> FireAndForgetSoundAssetList;

	TMap<FName, USoundWave*> FireAndForgetSoundList;

	UAudioComponent* CreateSoundComponent(FName SoundName, TAssetPtr<USoundWave> SoundWaveAsset);

	USoundWave* CreateFireAndForgetSound(FName SoundName, TAssetPtr<USoundWave> SoundWaveAsset);
	
};
