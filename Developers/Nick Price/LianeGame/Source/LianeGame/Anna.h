// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LianeGameCharacter.h"
#include "Anna.generated.h"

class UPointLightComponent;
class USpotLightComponent;
class UPhysicsHandleComponent;
class USphereComponent;
class UHealthComponent;
class USceneComponent;
class ATKShield;
/**
 * Third Person protagonist that uses telekinesis 
 */
UCLASS()
class LIANEGAME_API AAnna : public ALianeGameCharacter
{
	GENERATED_BODY()
	
public:

	AAnna();
	~AAnna();

	virtual void Tick(float DeltaTime) override;

	// How far ahead of the player can we reach in cm
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float Reach;

	//The strength of the telekinesis throw
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float ThrowStrength;

	//How long is the shield active?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	int32 ShieldLifetime = 5;

	//The time it takes to recharge the shield
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	int32 ShieldCooldown = 30;

	//Can Anna use her shield in a level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	bool bCanUseShield;

	//Can Anna use her shield in a level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	bool bCanUseTelekinesis;
	
	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();

	UFUNCTION(BlueprintNativeEvent)
	void CooldownHasFinished();

protected:


	bool bInvertY; //Invert the Y axis for aiming
	bool bInvertX; //Invert the X axis for aiming

	float aimSensitivity = 1.0f;

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera" ,meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	/* Pawn died previously */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	bool bDied;

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UHealthComponent* HealthComp;

	UFUNCTION()
	void OnHealthChanged(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* ShieldSpawner;

	UPROPERTY()
	ATKShield* Shield;

	UPROPERTY(EditAnywhere, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ATKShield> ShieldBlueprint;

	// Ray-cast and grab what's in reach
	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void Grab();

	// Called when grab is released
	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void Release();

	//Throw the object the player is grabbing
	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void TKThrow();

	//Make player face the telekinesis object they are grabbing
	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void FaceTKObject();

	//Recover the player's health
	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void TKHeal();

	//Generates a force field that deflects objects
	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void TKShield();

	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void ActivateShield();

	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void RechargeShield();


	// Set (assumed) phyics handle location
	void SetPhysicsHandleLocation();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns current start of reach line
	FVector GetTKReachLineStart();

	// Returns current end of reach line
	FVector GetTKReachLineEnd();

	//Is the shield ready to go?
	bool bIsReady();

	FTimerHandle RechargeTimerHandle;

	FTimerHandle ShieldTimerHandle;
};
