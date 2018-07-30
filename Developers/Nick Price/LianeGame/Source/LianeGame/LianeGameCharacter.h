#pragma once

#include "LGGameInstance.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LianeGameCharacter.generated.h"

class UPointLightComponent;
class USpotLightComponent;
class UPhysicsHandleComponent;
class USphereComponent;
class UHealthComponent;

UCLASS(config = Game)
class ALianeGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALianeGameCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	//The direction which the grabbed object is pulled
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float PullDirection;

	// How far ahead of the player can we reach in cm
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float TK_Reach;

	//The strength of the telekinesis throw
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Telekinesis")
	float ThrowStrength;

protected:

	virtual void BeginPlay() override;

	UPROPERTY()
	class UAnimInstance* animInstance;

	void TurnAtRate(float Rate);

	void LookUpAtRate(float Rate);

	bool bWantsToZoom;

	UPROPERTY(EditDefaultsOnly, Category = "Player")
	float ZoomedFOV;

	UPROPERTY(EditDefaultsOnly, Category = "Player", meta = (ClampMin = 0.1, ClampMax = 100))
	float ZoomInterpSpeed;

	/* Default FOV set during begin play */
	float DefaultFOV;

	void BeginZoom();

	void EndZoom();

	UPROPERTY(VisibleDefaultsOnly, Category = "Player")
	FName WeaponAttachSocketName;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UHealthComponent* HealthComp;

	UFUNCTION()
	void OnHealthChanged(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	/* Pawn died previously */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	bool bDied;

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	/*
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
	//UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void TKHeal();

	//Generates a force field that deflects objects
	UFUNCTION(BlueprintCallable, Category = "Telekinesis", meta = (AllowPrivateAccess = "true"))
	void TKShield();

	// Set (assumed) phyics handle location
	void SetPhysicsHandleLocation();

	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();

	// Returns current start of reach line
	FVector GetTKReachLineStart();

	// Returns current end of reach line
	FVector GetTKReachLineEnd();

	FRotator StoredRot;
	*/
public:

	virtual void Tick(float DeltaTime) override;
	void MoveForward(float v);
	void MoveLeftRight(float h);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

