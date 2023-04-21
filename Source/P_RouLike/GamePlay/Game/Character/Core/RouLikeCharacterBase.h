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

	/*��ʼ����ɫ����*/
	UFUNCTION(NetMulticast,Reliable)
	void UpdateCharacterAttribute(const FCharacterAttributeTable& CharacterAttributeTable);

	/*�Ƿ�����*/
	bool IsDie();

	/*���ù���id*/
	void SetHitID(int32 InNewID);
	const int32 GetHitID() const;

	/*������*/
	virtual void PlayHit();
	virtual void PlayDie();

	virtual void HandleHealth(ARouLikeCharacterBase* InstigatorPawn,
	AActor* DamageCauser,const struct FGameplayTagContainer& InTags,
	float InNewValue ,bool bPlayHit=true);
	
	/*�����ź�*/
	int32 GetDieIndex(){return DieIndex;};
	virtual void AnimSignal(int32 InSignal);
	UFUNCTION(BlueprintCallable,BlueprintImplementableEvent,DisplayName="AnimSignal",Category="AnimEvent")
	void K2_AnimSignal(int32 InSignal);

	/*��ȡѪ��*/
	UWidget* GetWidget();
	void IsHideWidget(bool IsHide);
	
protected:
	FORCEINLINE UFightComponent* GetFightComponent() { return FightComponents; }

	/*�������*/
	UPROPERTY(Category=RouLikeComponent,BlueprintReadOnly,VisibleAnywhere)
	TObjectPtr<UFightComponent>  FightComponents;
	
	/*GAS�������*/
	UPROPERTY(Category=RouLikeComponent,BlueprintReadOnly,VisibleAnywhere)
	TObjectPtr<URouLikeAbilitySystemComponent>  AbilitySystemComponent;

	/*GAS ��ɫ�������*/
	UPROPERTY(Category = MMOARPGCharacterBase, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<URouLikeAttributeSet> AttributeSet;

	/*Ѫ�����*/
	UPROPERTY(Category = MMOARPGCharacterBase, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UWidgetComponent> Widget;

	/*CharacterID Ϊ�˴ӱ��в���Լ��ļ��ܻ�������Ϣ*/
	UPROPERTY(EditDefaultsOnly,Category="Cahracter")
	int32 ID;

	/*����״̬*/
	UPROPERTY()
	int32 DieIndex;
};



