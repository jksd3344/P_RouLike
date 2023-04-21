// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/Core/GamePlayAbilityCore.h"
#include "GamePlayAbilitySkill.generated.h"

/**
 * 
 */
UCLASS()
class P_ROULIKE_API UGamePlayAbilitySkill : public UGamePlayAbilityCore
{
	GENERATED_BODY()
public:
	virtual void OnCompleted();
	
	virtual void OnBlendOut();

	virtual void OnInterrupted();

	virtual void OnCancelled();
};
