// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TrajectoryGenerator.h"
#include "Core/RouLikeAnimInstanceBase.h"
#include "RouLikeCharacterAnimInstance.generated.h"
class ARouLikeCharacter;
class UDistanceMatching;
/**
 * 
 */
UCLASS()
class P_ROULIKE_API URouLikeCharacterAnimInstance : public URouLikeAnimInstanceBase
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable,BlueprintPure)
	ARouLikeCharacter* GetRouLikeCharacter();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	virtual void NativeBeginPlay() override;
protected:
	UPROPERTY(BlueprintReadWrite)
	UTrajectoryGenerator *TrajectoryGenerator;

	UPROPERTY(BlueprintReadWrite)
	UDistanceMatching *DistanceMatching;

	UPROPERTY(BlueprintReadWrite)
	FTrajectory Trajectory;

	UPROPERTY(BlueprintReadWrite)
	bool HasMoveInput;

	UPROPERTY(BlueprintReadWrite)
	bool IsMoving;
};