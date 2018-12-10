// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Interface.h"
#include "P1toP2Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UP1toP2Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LIANEGAME_API IP1toP2Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Player interface")
	void CallPlayerTwo(float value);
};
