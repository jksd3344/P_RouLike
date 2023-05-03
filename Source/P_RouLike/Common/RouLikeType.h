// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/DataTable/RouLikeTableBase.h"
#include "RouLikeType.generated.h"

enum class ECharacterType: uint8
{
	CHARACTER_NONE				 UMETA(DisplayName = "None"),			//1 主角
	CHARACTER_PLAYER_MAIN		 UMETA(DisplayName = "Lead"),			//1 主角
	CHARACTER_PARTNER			 UMETA(DisplayName = "Partner"),		//2 ~ 4096 //配角
	CHARACTER_NPC_RESIDENT		 UMETA(DisplayName = "Resident"),		//4097 ~ 8119 //居民
	CHARACTER_NPC_GUARDIAN		 UMETA(DisplayName = "Guardian"),		//8120 ~ 16423 //守卫者
	CHARACTER_MONSTER			 UMETA(DisplayName = "Monster"),		//16424~30000	//小怪
	CHARACTER_BOSS				 UMETA(DisplayName = "Boss"),			//30001			//Boss
};

inline const FString RoleEnumToString(ENetRole InCurrentState)
{
	switch (InCurrentState)
	{
	case ROLE_Authority:
		return TEXT("ROLE_Authority");
	case ROLE_SimulatedProxy:
		return TEXT("ROLE_SimulatedProxy");
	case ROLE_AutonomousProxy:
		return TEXT("ROLE_AutonomousProxy");
	default:;
	}
	ensure(false);
	return TEXT("Unknown");
}


USTRUCT(BlueprintType)
struct P_ROULIKE_API FRouLikeAttributeData
{
	GENERATED_USTRUCT_BODY()
	FRouLikeAttributeData();
		
	float BaseValue;
	float CurrentValue;
};


USTRUCT(BlueprintType)
struct FRouLikeSlotData
{
	GENERATED_BODY()

	FRouLikeSlotData();

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