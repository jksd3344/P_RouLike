// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "P_RouLike/UI/Game/UI_MainScreen.h"
#include "P_RouLikeHUD.generated.h"


/**
 * 
 */
UCLASS()
class P_ROULIKE_API AP_RouLikeHUD : public AHUD
{
	GENERATED_BODY()
public:	
	AP_RouLikeHUD();
	
	virtual void BeginPlay() override;


	UUI_MainScreen* GetMainScreen();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<UUI_MainScreen> MainScreenClass;

private:
    UPROPERTY()
	UUI_MainScreen* MainScreen;
};

