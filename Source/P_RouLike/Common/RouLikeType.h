// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/GamePlay/Game/Character/Core/RouLikeCharacterBase.h"
#include "RouLikeType.generated.h"

USTRUCT(BlueprintType)
struct P_ROULIKE_API FRouLikeAttributeData
{
	GENERATED_USTRUCT_BODY()
	FRouLikeAttributeData();
		
	float BaseValue;
	float CurrentValue;
};


USTRUCT(BlueprintType)
struct FSlotData
{
	GENERATED_BODY()

	FSlotData();

	UPROPERTY()
	int32 SlotID;
	
	UPROPERTY(EditDefaultsOnly, Category = "Slot")
	UTexture2D* SlotICO;

	UPROPERTY(EditDefaultsOnly, Category = "Slot")
	ESlotPropType PropType;

	UPROPERTY()
	float CD;
	
	UPROPERTY()
	int32 Number;//-1不可 是否是可以重叠的

	void Reset();
};