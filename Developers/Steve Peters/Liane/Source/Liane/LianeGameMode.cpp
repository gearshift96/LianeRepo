// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "LianeGameMode.h"
#include "LianeHUD.h"
#include "LianeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALianeGameMode::ALianeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ALianeHUD::StaticClass();
}
