// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimNotify_FaceTarget.generated.h"

/**
 * 
 */
UCLASS(meta=(DisplayName="FaceTarget"))
class P_ROULIKE_API UAnimNotify_FaceTarget : public UAnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_FaceTarget();

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};