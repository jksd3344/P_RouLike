// Copyright Epic Games, Inc. All Rights Reserved.

#include "P_RouLikePlayerController.h"

AP_RouLikePlayerController::AP_RouLikePlayerController()
{
	bShowMouseCursor = true;
}

void AP_RouLikePlayerController::PickUpProp_Implementation()
{
}

void AP_RouLikePlayerController::BuyProp_Implementation()
{
}

void AP_RouLikePlayerController::Sell_Implementation(int32 InMoveInventoryID, int32 InItemId)
{
}

void AP_RouLikePlayerController::Use_Implementation(int32 InMoveInventoryID)
{
}

void AP_RouLikePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}





