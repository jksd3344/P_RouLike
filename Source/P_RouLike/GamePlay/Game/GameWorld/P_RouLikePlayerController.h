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

	
	/*ʰȡ��ƷWidget��ʾ*/
	UFUNCTION(Client,Reliable)
	void PickUpPropClueForWidet(bool IsHidWdiget);

	/*ʰȡ��Ʒ*/
	UFUNCTION(Server,Reliable)
	void PickUpProp(ATriggerActor* TriggerActor,ARoulikeWenpon* WenponActor);
protected:
	
	/*������Ʒ*/
	UFUNCTION(Server,Reliable)
	void BuyProp();

	/*�۳�*/
	UFUNCTION(Server,Reliable)
	void Sell(int32 InMoveInventoryID,int32 InItemId);

	/*ʹ��*/
	UFUNCTION(Server,Reliable)
	void Use(int32 InMoveInventoryID);

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;

};


