// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "RouLikeTableBase.generated.h"

//��Ʒ����
UENUM(BlueprintType)
enum class ESlotPropType :uint8
{
	SLOT_ALL			UMETA(DisplayName = "All"),        /*ȫ��*/
	SLOT_CONSUMABLES	UMETA(DisplayName = "Consumables"),/*�Ĳ�*/

	SLOT_ARMS           UMETA(DisplayName = "ARMS"),       /*����*/	
	SLOT_HELMET         UMETA(DisplayName = "HELMET"),	   /*ͷ��*/
	SLOT_ARMOR          UMETA(DisplayName = "ARMOR"),	   /*����*/
	SLOT_HALO           UMETA(DisplayName = "HALO"),	   /*�⻷*/
	SLOT_SACREDOBJ      UMETA(DisplayName = "SACREDOBJ"),  /*����*/

};


USTRUCT(BlueprintType)
struct FRouLikeTableBase:public FTableRowBase
{
	GENERATED_BODY();
	FRouLikeTableBase();

	UPROPERTY(EditDefaultsOnly, Category = "ID")
	int32 ID;
};

