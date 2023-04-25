// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Border.h"
#include "P_RouLike/UI/Core/UI_Base.h"
#include "UI_PickButton.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class P_ROULIKE_API UUI_PickButton : public UUI_Base
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	UBorder* KeyBorder;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* KeyButton;
protected:
	virtual void NativeConstruct();
};