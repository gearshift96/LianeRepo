#pragma once

#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"
#include "Engine.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "LianeGameCharacter.generated.h"

UCLASS(config = Game)
class ALianeGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
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

	//Invert the Y axis for aiming/camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	bool bInvertY;

	//Invert the X axis for aiming/camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	bool bInvertX;

	//Adjust camera/aim sensitivity
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	float aimSensitivity = 1.0f;

	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Config")
	bool bIsInsideAnyLight;
};

