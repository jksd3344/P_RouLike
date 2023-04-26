// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbilitySpec.h"
#include "Core/MotionComponent.h"
#include "P_RouLike/GamePlay/Common/ComBat/CombatType.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/RouLikeAbilitySystemComponent.h"
#include "FightComponent.generated.h"

class ARouLikeCharacterBase;
class AP_RouLikeGameState;
class UGamePlayAbilityCore;
UCLASS(Blueprintable)
class UFightComponent : public UMotionComponent
{
	GENERATED_BODY()
public:
	UFightComponent();

	virtual void BeginPlay() override;

	FRouLikeCombat* GetCombatInfo(){return &CombatAttack;}

	void RouLikeGameplayAbility(const FName &InKey);

	FGameplayAbilitySpecHandle AddAbility(TSubclassOf<UGameplayAbility>InNewAbility);

	UFUNCTION(BlueprintCallable)
	bool Attack(const FName& Index);

	void Press();

	void Released();

	void Reset();

	bool TryActivateAbility(const FName& InTagName,const TMap<FName, FGameplayAbilitySpecHandle> &InMap);

	void RegisterComboAttack(FRouLikeCombat& InComboAttack, const FName& Key);

	void RepickRegisterComboAttack();

	UGamePlayAbilityCore *GetGameplayAbility(const FName &InKey);
	
	/*GAS Skill*/
	UFUNCTION(BlueprintCallable)
    void Hit();

	UFUNCTION(BlueprintCallable)
	void Die();
	
	virtual void HandleHealth(ARouLikeCharacterBase* InstigatorPawn,AActor* DamageCauser, const struct FGameplayTagContainer& InTags,float InNewValue, bool bPlayHit = true);
public:
	UPROPERTY()
	int32 HitID;
protected:
	TMap<FName, FGameplayAbilitySpecHandle> Skills;

	UPROPERTY()
	FRouLikeCombat CombatAttack;

	UPROPERTY()
	TWeakObjectPtr<URouLikeAbilitySystemComponent> AbilitySystemComponent;
};