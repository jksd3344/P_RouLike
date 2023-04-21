// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Engine/DataTable.h"
#include "CharacterAttributeTable.generated.h"

USTRUCT()
struct FCharacterAttributeTable:public FTableRowBase
{
	GENERATED_BODY()

	FCharacterAttributeTable();

	UPROPERTY(EditDefaultsOnly, Category = "CharacterAttribute")
	int32 ID;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterAttribute")
	float Health;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterAttribute")
	float PhysicsAttack;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterAttribute")
	TArray<FGameplayTag> SkillsTags;
};


