// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LianeGameCharacter.h"
#include "Robert.generated.h"

class UInputComponent;
class USpotLightComponent;
class UHealthComponent;

/**
 * First Person protagonist that uses hacking skills to solve puzzles
 */

UCLASS()
class LIANEGAME_API ARobert : public ALianeGameCharacter
{
	GENERATED_BODY()

public:
	ARobert();
	~ARobert();

	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

	//Recover the player's health
	UFUNCTION(BlueprintCallable, Category = "Hacking")
	void Heal();

	/* Pawn died previously */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	bool bDied;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UHealthComponent* HealthComp;

	UFUNCTION()
	void OnHealthChanged(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

};











