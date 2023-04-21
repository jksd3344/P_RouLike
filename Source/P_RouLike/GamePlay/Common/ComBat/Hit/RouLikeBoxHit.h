// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitType/HitCollisionBox.h"
#include "RouLikeBoxHit.generated.h"

UCLASS(BlueprintType,Blueprintable)
class P_ROULIKE_API ARouLikeBoxHit:public AHitCollisionBox
{
	GENERATED_BODY()
	
public:
	ARouLikeBoxHit(const FObjectInitializer& ObjectInitializer);

	virtual void HandleDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};

