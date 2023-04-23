// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RouLikeTableBase.h"
#include "P_RouLike/GamePlay/Wenpon/Core/RoulikePropBase.h"
#include "SlotTable.generated.h"



USTRUCT()
struct FSlotTable:public FRouLikeTableBase
{
	GENERATED_BODY()
	FSlotTable();
	
	UPROPERTY(EditDefaultsOnly, Category = "Slot")
	FName SlotName;

	UPROPERTY(EditDefaultsOnly, Category = "Slot")
	UTexture2D* SlotIcon;

	UPROPERTY(EditDefaultsOnly, Category = "Slot")
	int32 SlotGold;

	UPROPERTY(EditDefaultsOnly, Category = "Slot")
	FText SlotIntroduction;

	UPROPERTY(EditDefaultsOnly, Category = "Slot")
	TArray<ESlotPropType> SlotType;
	
	UPROPERTY(EditDefaultsOnly, Category = "Slot")
	TSubclassOf<ARoulikePropBase> PropClass;
};
