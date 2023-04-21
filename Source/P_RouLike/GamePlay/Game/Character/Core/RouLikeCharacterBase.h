// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Character.h"
#include "P_RouLike/DataTable/CharacterAttributeTable.h"
#include "P_RouLike/GamePlay/Common/ComBat/CombatInterface/CombatInterface.h"
#include "P_RouLike/GamePlay/Component/FightComponent.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/RouLikeAbilitySystemComponent.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/RouLikeAttributeSet.h"
#include "RouLikeCharacterBase.generated.h"

UCLASS(Blueprintable)
class ARouLikeCharacterBase : public ACharacter,public ICombatInterface
{
	GENERATED_BODY()

public:
	ARouLikeCharacterBase();
	
	virtual void CombatReset();
	
	virtual void Tick(float DeltaSeconds) override;

	virtual FRouLikeCombat* GetCombatInfo();

	virtual void ComboAttack(const FName &InKey);
	
	UFUNCTION(BlueprintCallable)
	void NormalAttack(const FName&  InKey);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent()const {return AbilitySystemComponent;}

	FORCEINLINE int32 GetID(){return ID;};

	/*初始化角色数据*/
	UFUNCTION(NetMulticast,Reliable)
	void UpdateCharacterAttribute(const FCharacterAttributeTable& CharacterAttributeTable);

	/*是否死亡*/
	bool IsDie();

	/*设置攻击id*/
	void SetHitID(int32 InNewID);
	const int32 GetHitID() const;

	/*被攻击*/
	virtual void PlayHit();
	virtual void PlayDie();

	virtual void HandleHealth(ARouLikeCharacterBase* InstigatorPawn,
	AActor* DamageCauser,const struct FGameplayTagContainer& InTags,
	float InNewValue ,bool bPlayHit=true);
	
	/*动画信号*/
	int32 GetDieIndex(){return DieIndex;};
	virtual void AnimSignal(int32 InSignal);
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent,DisplayName="AnimSignal",Category="AnimEvent")
	void K2_AnimSignal(int32 InSignal);

	/*获取血条*/
	UWidget* GetWidget();
	void IsHideWidget(bool IsHide);
	
protected:
	FORCEINLINE UFightComponent* GetFightComponent() { return FightComponents; }

	/*攻击组件*/
	UPROPERTY(Category=RouLikeComponent,BlueprintReadOnly,VisibleAnywhere)
	TObjectPtr<UFightComponent>  FightComponents;
	
	/*GAS技能组件*/
	UPROPERTY(Category=RouLikeComponent,BlueprintReadOnly,VisibleAnywhere)
	TObjectPtr<URouLikeAbilitySystemComponent>  AbilitySystemComponent;

	/*GAS 角色属性组件*/
	UPROPERTY(Category = MMOARPGCharacterBase, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<URouLikeAttributeSet> AttributeSet;

	/*血条组件*/
	UPROPERTY(Category = MMOARPGCharacterBase, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UWidgetComponent> Widget;

	/*CharacterID 为了从表中查出自己的技能或其他信息*/
	UPROPERTY(EditDefaultsOnly,Category="Cahracter")
	int32 ID;

	/*死亡状态*/
	UPROPERTY()
	int32 DieIndex;
};



