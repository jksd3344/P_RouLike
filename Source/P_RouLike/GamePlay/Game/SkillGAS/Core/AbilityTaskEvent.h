// Copyright Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "AbilityTaskEvent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMontageWaitForDamageEventDelegate,FGameplayTag, EventTag, FGameplayEventData, EventData);
/** Ability task to simply play a montage. Many games will want to make a modified version of this task that looks for game-specific events */
UCLASS()
class P_ROULIKE_API UAbilityTaskEvent : public UAbilityTask_PlayMontageAndWait
{
	GENERATED_BODY()
public:
	UAbilityTaskEvent(const FObjectInitializer& ObjectInitializer);

	//伤害通知
	UPROPERTY(BlueprintAssignable)
	FMontageWaitForDamageEventDelegate DamageEventReceived;

	//返回自己注册通知
	static UAbilityTaskEvent* CreateAbilityTaskEventProxy(
		UGameplayAbility* OwningAbility,
		FName TaskInstanceName,
		UAnimMontage* MontageToPlay, 
		FGameplayTagContainer InEventTags,
		float Rate = 1.f,
		FName StartSection = NAME_None, 
		bool bStopWhenAbilityEnds = true, 
		float AnimRootMotionTranslationScale = 1.f,
		float StartTimeSeconds = 0.f);

	virtual void Activate() override;
private:
	void OnDamageGameplayEvent(FGameplayTag InGameplayTag, const FGameplayEventData* Payload);
	
	virtual void OnDestroy(bool bInOwnerFinished) override;

	UPROPERTY()
	FGameplayTagContainer EventTags;

	FDelegateHandle DamageEventHandle;
};