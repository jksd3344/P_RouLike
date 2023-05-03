// Copyright Epic Games, Inc. All Rights Reserved.

#include "P_RouLikePlayerController.h"
#include "P_RouLikeHUD.h"
#include "P_RouLikePlayerState.h"
#include "P_RouLike/GamePlay/Wenpon/RoulikeWenpon.h"
#include "P_RouLike/GamePlay/Wenpon/TriggerActor.h"

AP_RouLikePlayerController::AP_RouLikePlayerController()
{
	bShowMouseCursor = true;
}

void AP_RouLikePlayerController::PickUpPropClueForWidet_Implementation(bool IsHidWdiget)
{
	if (AP_RouLikeHUD* RouLikeHUD =  Cast<AP_RouLikeHUD>(GetHUD()))
	{
		RouLikeHUD->GetMainScreen()->SetPickButtonVisiable(IsHidWdiget);
	}
}

void AP_RouLikePlayerController::PickUpProp_Implementation(ATriggerActor* TriggerActor,ARoulikeWenpon* WenponActor)
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


void AP_RouLikePlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (GetPawn())
	{
		if (GetLocalRole()==ENetRole::ROLE_AutonomousProxy||GetLocalRole() == ENetRole::ROLE_SimulatedProxy)
		{
			
		}
		
	}
}





