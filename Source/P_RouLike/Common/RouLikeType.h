// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RouLikeType.generated.h"

USTRUCT(BlueprintType)
struct P_ROULIKE_API FRouLikeAttributeData
{
	GENERATED_USTRUCT_BODY()
	FRouLikeAttributeData();
		
	float BaseValue;
	float CurrentValue;
};