// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RouLikeType.h"

namespace RouLikeGameMethod
{
	ARouLikeCharacterBase *FindTarget(ARouLikeCharacterBase* InThis,const TArray<ECharacterType>&InIgnoreType,float InRange=500.f);

	ECharacterType GetCharacterType(int32 InCharacterID);
}
