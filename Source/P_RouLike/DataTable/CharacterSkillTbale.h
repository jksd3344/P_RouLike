// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Engine/DataTable.h"
#include "CharacterSkillTbale.generated.h"

USTRUCT()
struct FCharacterSkillTable:public FTableRowBase
{
	GENERATED_BODY()

	FCharacterSkillTable();

	UPROPERTY(EditDefaultsOnly, Category = "CharacterSkill")
	int32 ID;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterSkill")
	UTexture2D* Icon;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterSkill")
	float CD;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterSkill")
	FText SkillAttributeTip;
	
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSkill")
	TSubclassOf<UGameplayAbility> GameplayAbility;
};


