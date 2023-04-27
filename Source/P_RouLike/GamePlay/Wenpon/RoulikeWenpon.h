// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Core/RoulikePropBase.h"
#include "RoulikeWenpon.generated.h"

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
	virtual void AttachWeapons(const USkeletalMeshComponent* StaticMeshComp){};

	/*更换装备*/
	UFUNCTION()
	virtual void ReplaceVenpon(){};

	/*注册装备技能*/
	UFUNCTION(BlueprintCallable)
	virtual void RegisterSkillToFightComponent(){};
};