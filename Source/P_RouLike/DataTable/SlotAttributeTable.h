// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RouLikeTableBase.h"
#include "Abilities/GameplayAbility.h"
#include "SlotAttributeTable.generated.h"

//����Ч��
UENUM()
enum class ESlotAttributeGainType:uint8
{
	SLOTATTRIBUTETYPE_ADD			UMETA(DisplayName = "Add"),
	SLOTATTRIBUTETYPE_SUBTRACT		UMETA(DisplayName = "Subtract"),
};

//��������
UENUM(BlueprintType)
enum class ESlotAttributeValueType :uint8
{
	SLOTATTRIBUTEVALUE_VALUE			UMETA(DisplayName = "Value"),		//ֵ
	SLOTATTRIBUTEVALUE_PERCENTAGE		UMETA(DisplayName = "Percentage"),	//�ٷֱ�
};

//���Լ���
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

	/*Ѫ��*/
	UPROPERTY(EditDefaultsOnly, Category = "Slot Attribute")
	FSlotAttributeValue Health;

	/*��������*/
	UPROPERTY(EditDefaultsOnly, Category = "Slot Attribute")
	FSlotAttributeValue PhysicalAttack;

	/*װ������*/
	UPROPERTY(EditDefaultsOnly, Category = "Slot Attribute")
	ESlotPropType AttributeType;

	/*���߻��߼��ܼ��*/
	UPROPERTY(EditDefaultsOnly, Category = "Slot Attribute")
	FSlotAttributeValue CD;

	/*��������*/
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSkill")
	TSubclassOf<UGameplayAbility> GameCombatAbility;

};

