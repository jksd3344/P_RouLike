// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "P_RouLikePlayerController.generated.h"

class ATriggerActor;
class ARoulikeWenpon;
UCLASS()
class AP_RouLikePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AP_RouLikePlayerController();

	
	/*拾取物品Widget提示*/
	UFUNCTION(Client,Reliable)
	void PickUpPropClueForWidet(bool IsHidWdiget);

	/*拾取物品*/
	UFUNCTION(Server,Reliable)
	void PickUpProp(ATriggerActor* TriggerActor,ARoulikeWenpon* WenponActor);
protected:
	
	/*购买物品*/
	UFUNCTION(Server,Reliable)
	void BuyProp();

	/*售出*/
	UFUNCTION(Server,Reliable)
	void Sell(int32 InMoveInventoryID,int32 InItemId);

	/*使用*/
	UFUNCTION(Server,Reliable)
	void Use(int32 InMoveInventoryID);

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;

};


