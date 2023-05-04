// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimNotify_CombatReset.generated.h"

/**
 * 
 */
UCLASS(meta=(DisplayName="CombatReset"))
class P_ROULIKE_API UAnimNotify_CombatReset : public UAnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_CombatReset();
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
	virtual FString GetNotifyName_Implementation() const override;

};