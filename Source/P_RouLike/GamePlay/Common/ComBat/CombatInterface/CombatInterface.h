// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/RouLikeAttributeSet.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable, BlueprintType, meta = (CannotImplementInterfaceInBlueprint))
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

/**
* 
*/
class P_ROULIKE_API ICombatInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void AnimSignal(int32 InSignal) {}
	virtual void CombatReset(){}
	virtual void ComboAttack(const FName &InKey) {}
	virtual struct FRouLikeCombat* GetCombatInfo() { return NULL; }
	virtual AActor* GetTarget() { return NULL; }
};
