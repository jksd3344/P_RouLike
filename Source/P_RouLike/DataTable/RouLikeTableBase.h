// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "RouLikeTableBase.generated.h"

//物品类型
UENUM(BlueprintType)
enum class ESlotPropType :uint8
{
	SLOT_ALL			UMETA(DisplayName = "All"),        /*全部*/
	SLOT_CONSUMABLES	UMETA(DisplayName = "Consumables"),/*耗材*/

	SLOT_ARMS           UMETA(DisplayName = "ARMS"),       /*武器*/	
	SLOT_HELMET         UMETA(DisplayName = "HELMET"),	   /*头盔*/
	SLOT_ARMOR          UMETA(DisplayName = "ARMOR"),	   /*防具*/
	SLOT_HALO           UMETA(DisplayName = "HALO"),	   /*光环*/
	SLOT_SACREDOBJ      UMETA(DisplayName = "SACREDOBJ"),  /*神器*/

};


USTRUCT(BlueprintType)
struct FRouLikeTableBase:public FTableRowBase
{
	GENERATED_BODY();
	FRouLikeTableBase();

	UPROPERTY(EditDefaultsOnly, Category = "ID")
	int32 ID;
};

