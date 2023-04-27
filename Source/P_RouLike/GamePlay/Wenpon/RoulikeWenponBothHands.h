// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoulikeWenpon.h"
#include "RoulikeWenponBothHands.generated.h"

/**
 * 
 */
UCLASS()
class P_ROULIKE_API ARoulikeWenponBothHands : public ARoulikeWenpon
{
	GENERATED_BODY()
public:
	ARoulikeWenponBothHands();

	virtual void AttachWeapons(const USkeletalMeshComponent* StaticMeshComp)override;

	virtual void RegisterSkillToFightComponent()override;

	virtual void ReplaceVenpon() override;
	
protected:
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	UStaticMeshComponent* ProMeshRightHandComponent;
};