// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LianeController.generated.h"

/**
 * 
 */

struct PlayerPawnData
{
	int32 Type;
};

UCLASS()
class LIANEGAME_API ALianeController : public APlayerController
{
	GENERATED_BODY()
	
public:
	PlayerPawnData CurrentPawnData;
	
};
