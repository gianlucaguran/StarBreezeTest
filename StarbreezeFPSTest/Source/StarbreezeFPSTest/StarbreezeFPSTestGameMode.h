// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StarbreezeFPSTestGameMode.generated.h"

UCLASS(minimalapi)
class AStarbreezeFPSTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AStarbreezeFPSTestGameMode();


	/** Score made by the player */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = "Score" )
		int m_iPlayerScore;

	/** Event to increase score */
	UFUNCTION( BlueprintNativeEvent, Category = "ScoreSystem" )
		void AddScore( int iPoints );
};



