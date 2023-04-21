// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "P_RouLikePlayerController.generated.h"

UCLASS()
class AP_RouLikePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AP_RouLikePlayerController();
	
protected:

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;

};


