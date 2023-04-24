// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/UI/Core/UI_Base.h"
#include "UI_CharacterInfo.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class P_ROULIKE_API UUI_CharacterInfo : public UUI_Base
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct();
};