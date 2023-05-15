// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/RouLikeAttributeSet.h"
#include "UObject/Interface.h"
#include "ALS_Character_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable, BlueprintType, meta = (CannotImplementInterfaceInBlueprint))
class UALS_Character_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
* 
*/
class P_ROULIKE_API IALS_Character_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ALSGetEssentialValue(
		FVector& Velocity,
		FVector& Acceleration,
		FVector& Movement,
		bool& IsMoving,
		bool& HasMovementInput,
		float& Speed,
		float &MovementInputAmout,
		FRotator& AimingRotation,
		float& AimYawRate
	){}
};
