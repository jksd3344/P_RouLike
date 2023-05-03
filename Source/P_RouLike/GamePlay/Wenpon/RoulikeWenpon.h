// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/RoulikePropBase.h"
#include "RoulikeWenpon.generated.h"

class URouLikeAbilitySystemComponent;
class URouLikeWenponAttributeSet;
/**
 * 
 */
UCLASS()
class P_ROULIKE_API ARoulikeWenpon : public ARoulikePropBase
{
	GENERATED_BODY()
public:
	ARoulikeWenpon();

	UFUNCTION()
	virtual void AttachWeapons(USkeletalMeshComponent* StaticMeshComp,const FName Socket);

	/*更换装备*/
	UFUNCTION()
	virtual void ReplaceWenpon(){};

	/*注册装备技能*/
	UFUNCTION(BlueprintCallable)
	virtual void RegisterSkillToFightComponent(const int32 WenponID,const FName& InKey);

protected:
	/*GAS技能组件*/
	UPROPERTY(Category=RouLikeComponent,BlueprintReadOnly,VisibleAnywhere)
	TObjectPtr<URouLikeAbilitySystemComponent>  WenponAbilitySystemComponent;

	/*GAS 角色属性组件*/
	UPROPERTY(Category = MMOARPGCharacterBase, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<URouLikeWenponAttributeSet> WenponAttributeSet;
};