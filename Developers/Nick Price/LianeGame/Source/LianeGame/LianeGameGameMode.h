#pragma once

#include "GameFramework/GameModeBase.h"
#include "LianeGameGameMode.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController);

UCLASS()
class ALianeGameGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALianeGameGameMode();

	UPROPERTY(BlueprintAssignable, Category = "GameMode")
	FOnActorKilled OnActorKilled;
};



