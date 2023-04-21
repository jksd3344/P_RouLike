// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MotionComponent.generated.h"

class ARouLikeCharacterBase;
UCLASS(Blueprintable)
class UMotionComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UMotionComponent();

	virtual void BeginPlay() override;
	
protected:
	UPROPERTY()
	TWeakObjectPtr<ARouLikeCharacterBase> RouLikeCharacterBase;

};