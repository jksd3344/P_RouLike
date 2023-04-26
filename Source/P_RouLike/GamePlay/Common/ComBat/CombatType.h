// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "CombatType.generated.h"


USTRUCT()
struct P_ROULIKE_API FRouLikeCombat
{
	GENERATED_BODY()

	FRouLikeCombat();

	/*连击序列下标*/
	UPROPERTY(EditDefaultsOnly, Category = ComboAttack)
	int32 CombatIndex;

	/*如果鼠标按下未松开*/
	UPROPERTY(EditDefaultsOnly, Category = ComboAttack)
	bool bLongPress;

	/*如果鼠标按下在state区间内*/
	UPROPERTY(EditDefaultsOnly, Category = ComboAttack)
	bool bShortPress;

	/*初始化第一次的combat*/
	UPROPERTY()
	FName ComboKey;

	/*最大连击数*/
	UPROPERTY()
	int32 MaxIndex;

	/*执行连击的character*/
	class ICombatInterface* Character;
	
	void UpdateCombatIndex();
	
	void Press();

	void Released();

	void Reset();
};
