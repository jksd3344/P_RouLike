// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "P_RouLike/Interface/ALS_Character_Interface.h"
#include "MotionALSComponent.generated.h"

class ARouLikeCharacter;

UCLASS(Blueprintable)
class P_ROULIKE_API UMotionALSComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMotionALSComponent();
	
	UFUNCTION(BlueprintCallable,BlueprintPure)
	ARouLikeCharacter* GetRouLikeCharacter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	
};
