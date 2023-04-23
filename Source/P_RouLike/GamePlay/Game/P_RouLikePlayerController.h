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
	/*ʰȡ��Ʒ*/
	UFUNCTION(Server,Reliable)
	void PickUpProp();
	
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


