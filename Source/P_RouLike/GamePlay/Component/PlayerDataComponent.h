// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Core/MotionComponent.h"
#include "P_RouLike/Common/RouLikeType.h"
#include "PlayerDataComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UPlayerDataComponent : public UMotionComponent
{
	GENERATED_BODY()
public:
	UPlayerDataComponent();

protected:
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};