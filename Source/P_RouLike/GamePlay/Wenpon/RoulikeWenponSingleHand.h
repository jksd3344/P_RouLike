// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoulikeWenpon.h"
#include "RoulikeWenponSingleHand.generated.h"

/**
 * 
 */
UCLASS()
class P_ROULIKE_API ARoulikeWenponSingleHand : public ARoulikeWenpon
{
	GENERATED_BODY()
public:
	ARoulikeWenponSingleHand();
	
	virtual void AttachWeapons(USkeletalMeshComponent* StaticMeshComp)override;


	virtual void ReplaceVenpon() override;
};