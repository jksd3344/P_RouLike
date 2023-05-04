// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RouLikeType.h"

namespace RouLikeGameMethod
{
	ARouLikeCharacterBase *FindTarget(ARouLikeCharacterBase* InThis,float InRange=500.f,const TArray<ECharacterType>&InIgnoreType = TArray<ECharacterType>());

	ECharacterType GetCharacterType(int32 InCharacterID);
}
