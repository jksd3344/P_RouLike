// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "CombatType.generated.h"


USTRUCT()
struct P_ROULIKE_API FRouLikeCombat
{
	GENERATED_BODY()

	FRouLikeCombat();

	/*���������±�*/
	UPROPERTY(EditDefaultsOnly, Category = ComboAttack)
	int32 CombatIndex;

	/*�����갴��δ�ɿ�*/
	UPROPERTY(EditDefaultsOnly, Category = ComboAttack)
	bool bLongPress;

	/*�����갴����state������*/
	UPROPERTY(EditDefaultsOnly, Category = ComboAttack)
	bool bShortPress;

	/*��ʼ����һ�ε�combat*/
	UPROPERTY()
	FName ComboKey;

	/*���������*/
	UPROPERTY()
	int32 MaxIndex;

	/*ִ��������character*/
	class ICombatInterface* Character;
	
	void UpdateCombatIndex();
	
	void Press();

	void Released();

	void Reset();
};
