// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityTaskEvent.h"
#include "Abilities/GameplayAbility.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/GamePlayAbilityType.h"
#include "GamePlayAbilityCore.generated.h"



/**
 * 
 */
UCLASS()
class P_ROULIKE_API UGamePlayAbilityCore : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UGamePlayAbilityCore();
	
	UFUNCTION()
	virtual void OnCompleted();

	UFUNCTION()
	virtual void OnBlendOut();

	UFUNCTION()
	virtual void OnInterrupted();

	UFUNCTION()
	virtual void OnCancelled();

	UFUNCTION(BlueprintImplementableEvent, Category = Ability, DisplayName = "OnCompleted", meta = (ScriptName = "OnCompleted"))
	bool K2_OnCompleted() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category = Ability, DisplayName = "OnBlendOut", meta = (ScriptName = "OnBlendOut"))
	bool K2_OnBlendOut() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category = Ability, DisplayName = "OnInterrupted", meta = (ScriptName = "OnInterrupted"))
	bool K2_OnInterrupted() const;
	
	UFUNCTION(BlueprintImplementableEvent, Category = Ability, DisplayName = "OnCancelled", meta = (ScriptName = "OnCancelled"))
	bool K2_OnCancelled() const;
	
	UFUNCTION(BlueprintCallable, Category = "MMOARPGGameplayAbility|Tasks")
	UAbilityTask_PlayMontageAndWait *PlayMontage(FName StartSection = NAME_None);

	UFUNCTION(BlueprintCallable, Category = "MMOARPGGameplayAbility|Tasks", meta = (DisplayName = "PlayMontageAndWait"))
	UAbilityTaskEvent* CreatePlayMontageAndWaitProxy(
		FName TaskInstanceName,
		UAnimMontage* InMontageToPlay, 
		float Rate = 1.f, 
		FName StartSection = NAME_None,
		bool bStopWhenAbilityEnds = true,
		float AnimRootMotionTranslationScale = 1.f,
		float StartTimeSeconds = 0.f);

	UFUNCTION()
	virtual	void OnDamageGameplayEvent(FGameplayTag InGameplayTag,FGameplayEventData Payload);

	int32 GetCompositeSectionsNumber();
protected:
	UPROPERTY(EditDefaultsOnly, Category = MontageAbility)
	UAnimMontage* MontageToPlay;

	//buf
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameplayEffects)
	TMap<FGameplayTag,FRouLikeGameplayEffects> EffectMap;

};
