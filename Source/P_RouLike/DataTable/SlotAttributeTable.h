// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RouLikeTableBase.h"
#include "Abilities/GameplayAbility.h"
#include "SlotAttributeTable.generated.h"

//增益效果
UENUM()
enum class ESlotAttributeGainType:uint8
{
	SLOTATTRIBUTETYPE_ADD			UMETA(DisplayName = "Add"),
	SLOTATTRIBUTETYPE_SUBTRACT		UMETA(DisplayName = "Subtract"),
};

//属性类型
UENUM(BlueprintType)
enum class ESlotAttributeValueType :uint8
{
	SLOTATTRIBUTEVALUE_VALUE			UMETA(DisplayName = "Value"),		//值
	SLOTATTRIBUTEVALUE_PERCENTAGE		UMETA(DisplayName = "Percentage"),	//百分比
};

//属性集合
USTRUCT(BlueprintType)
struct FSlotAttributeValue
{
	GENERATED_BODY()
	FSlotAttributeValue();

	UPROPERTY(EditDefaultsOnly, Category = "Attribute Value")
	ESlotAttributeGainType GainType;

	UPROPERTY(EditDefaultsOnly, Category = "Attribute Value")
	ESlotAttributeValueType ValueType;

	UPROPERTY(EditDefaultsOnly, Category = "Attribute Value")
	float Value;
};

USTRUCT()
struct FSlotAttributeTable:public FRouLikeTableBase
{
	GENERATED_BODY()
	FSlotAttributeTable();

	/*血量*/
	UPROPERTY(EditDefaultsOnly, Category = "Slot Attribute")
	FSlotAttributeValue Health;

	/*基础攻击*/
	UPROPERTY(EditDefaultsOnly, Category = "Slot Attribute")
	FSlotAttributeValue PhysicalAttack;

	/*装备类型*/
	UPROPERTY(EditDefaultsOnly, Category = "Slot Attribute")
	ESlotPropType AttributeType;

	/*道具或者技能间隔*/
	UPROPERTY(EditDefaultsOnly, Category = "Slot Attribute")
	FSlotAttributeValue CD;

	/*基础技能*/
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSkill")
	TSubclassOf<UGameplayAbility> GameCombatAbility;

};

