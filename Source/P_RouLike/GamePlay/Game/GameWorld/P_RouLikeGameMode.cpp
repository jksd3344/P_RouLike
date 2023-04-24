// Copyright Epic Games, Inc. All Rights Reserved.

#include "P_RouLikeGameMode.h"
#include "P_RouLikePlayerController.h"
#include "GameFramework/Character.h"

AP_RouLikeGameMode::AP_RouLikeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AP_RouLikePlayerController::StaticClass();
	
}	