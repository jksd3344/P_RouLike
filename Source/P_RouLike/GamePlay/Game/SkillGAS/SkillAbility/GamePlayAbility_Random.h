// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GamePlayAbilitySkill.h"
#include "GamePlayAbility_Random.generated.h"

/**
 * 
 */
UCLASS()
class P_ROULIKE_API UGamePlayAbility_Random : public UGamePlayAbilitySkill
{
	GENERATED_BODY()
public:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;
};
