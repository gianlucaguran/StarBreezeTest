// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "StarbreezeFPSTestGameMode.h"
#include "StarbreezeFPSTestHUD.h"
#include "StarbreezeFPSTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStarbreezeFPSTestGameMode::AStarbreezeFPSTestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AStarbreezeFPSTestHUD::StaticClass();
}

void AStarbreezeFPSTestGameMode::AddScore_Implementation( int iPoints )
{
	m_iPlayerScore += iPoints;
}
