// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once

#include "AbilitySystemComponent.h"
#include "RouLikeAbilitySystemComponent.generated.h"

UCLASS()
class P_ROULIKE_API URouLikeAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	URouLikeAbilitySystemComponent();
	
	static URouLikeAbilitySystemComponent* GetAbilitySystemComponentFromActor(const AActor* Actor, bool LookForComponent = false);

	
};