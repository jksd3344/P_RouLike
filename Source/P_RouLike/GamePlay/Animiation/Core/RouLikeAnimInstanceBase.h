// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RouLikeAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class P_ROULIKE_API URouLikeAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
public:
	URouLikeAnimInstanceBase();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttrubute")
	int32 DieIndex;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AnimAttrubute")
	bool bDeath;

};