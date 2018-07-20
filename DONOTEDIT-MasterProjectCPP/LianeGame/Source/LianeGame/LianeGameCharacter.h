// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LianeGameCharacter.generated.h"

class UPointLightComponent;
class USpotLightComponent;
class UPhysicsHandleComponent;
class USphereComponent;

UCLASS(config=Game)
class ALianeGameCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Telekinesis camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TKCamera;

public:
	ALianeGameCharacter();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime);

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	//The direction which the grabbed object is pulled
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float PullDirection;

	// How far ahead of the player can we reach in cm
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float TK_Reach;

	// The height of the grabbed object from the ground in cm
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float TK_Height;

	//The strength of the telekinesis throw
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float ThrowStrength;

	//The strength of the telekinesis throw
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	bool bIsInTK;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

private:

	FRotator ControlRotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	// Ray-cast and grab what's in reach
	void Grab();

	// Called when grab is released
	void Release();

	//Throw the object the player is grabbing
	void Throw();

	//Make player face the telekinesis object they are grabbing
	void FaceTKObject();

	// Set (assumed) phyics handle location
	void SetPhysicsHandleLocation();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns current start of reach line
	FVector GetTKReachLineStart();

	// Returns current end of reach line
	FVector GetTKReachLineEnd();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Returns TelekinesisCamera subobject **/
	FORCEINLINE class UCameraComponent* GetTKCamera() const { return TKCamera; }

};

