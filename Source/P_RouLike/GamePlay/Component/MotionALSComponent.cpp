// Fill out your copyright notice in the Description page of Project Settings.
#include "MotionALSComponent.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"


// Sets default values for this component's properties
UMotionALSComponent::UMotionALSComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

ARouLikeCharacter* UMotionALSComponent::GetRouLikeCharacter()
{
	if (ARouLikeCharacter* InCharacter = Cast<ARouLikeCharacter>(GetOwner()))
	{
		return InCharacter;
	}
	return NULL;
}

void UMotionALSComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UMotionALSComponent::TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

