// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/UI/Core/UI_Base.h"
#include "UI_CharacterBarWidget.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class P_ROULIKE_API UUI_CharacterBarWidget : public UUI_Base
{
	GENERATED_BODY()


	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthBar;
	
public:
	void SetHealth(float InPercentage);
	
protected:
	virtual void NativeConstruct();
};