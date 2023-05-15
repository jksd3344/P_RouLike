// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AN_ChageCheck.generated.h"

/**
 * 
 */
UCLASS(meta=(DisplayName="Attack"))
class P_ROULIKE_API UAN_ChageCheck : public UAnimNotify
{
	GENERATED_BODY()
public:
	UAN_ChageCheck();
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
	virtual FString GetNotifyName_Implementation() const override;
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Special")
	bool bSpecial;
};