// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "GamePlayAbilityType.generated.h"

USTRUCT(BlueprintType)
struct FRouLikeGameplayEffects
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffects)
	TArray<TSubclassOf<UGameplayEffect>> TargetEffectClasses;
};


USTRUCT(BlueprintType)
struct FRouLikeGameplayEffectSpec
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffects)
	FGameplayAbilityTargetDataHandle TargetHandleData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameplayEffects)
	TArray<FGameplayEffectSpecHandle> TargetEffectSpecs;

};

