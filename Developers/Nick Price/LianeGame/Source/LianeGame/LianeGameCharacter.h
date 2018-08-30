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
class USceneComponent;
class ATKShield;

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
	UPROPERTY(BlueprintReadWrite, Category = "Telekinesis")
	bool bCanUseTelekinesis;

	//Can Robert use his hacking skills
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hacking")
	bool bCanHack;

	//The amount of health Anna/Robert heal
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	float HealAmount;

	//The rate of which health is recovered
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	float HealTickInterval;

	//Can Anna/Robert heal themselves in a level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	bool bCanHeal;

	//Can Anna/Robert shoot with a weapon in a level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
	bool bCanShoot;

	UFUNCTION(BlueprintNativeEvent)
	void CountdownHasFinished();

	UFUNCTION(BlueprintNativeEvent)
	void CooldownHasFinished();
	

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

	UPROPERTY(BlueprintReadWrite, Category = "Components")
	UHealthComponent* HealthComp;

	UFUNCTION()
	void OnHealthChanged(UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	/* Pawn died previously */
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	bool bDied;

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

