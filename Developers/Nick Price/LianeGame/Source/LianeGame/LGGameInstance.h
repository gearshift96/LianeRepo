// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "LGGameInstance.generated.h"

//------------------------------------------------------------
//------------------------------------------------------------
USTRUCT(BlueprintType)
struct FSoundResult
{
	GENERATED_BODY()

	FSoundResult();

	UPROPERTY()
	bool bSuccess;

	UPROPERTY()
	bool bNew;

	UPROPERTY()
	USoundWave* SoundWave;
};

//------------------------------------------------------------
//------------------------------------------------------------
class LGPersistentData
{
public:
	LGPersistentData();
	FStreamableManager StreamableManager;
	TMap<TAssetPtr<USoundWave>, USoundWave*> SoundWaveList;
};

//------------------------------------------------------------
//------------------------------------------------------------
UCLASS()
class LIANEGAME_API ULGGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	ULGGameInstance();

	UFUNCTION(BlueprintCallable, Category = "C++Function")
	FSoundResult AddToSoundWaveList(TAssetPtr<USoundWave> SoundWaveAsset);

	UFUNCTION(BlueprintCallable, Category = "C++Function")
	FSoundResult GetSoundWaveFromList(TAssetPtr<USoundWave> SoundWaveAsset);
protected:
	LGPersistentData PersistentData;
	
};
