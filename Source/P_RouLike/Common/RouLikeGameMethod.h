// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RouLikeType.h"

namespace RouLikeGameMethod
{
	ARouLikeCharacterBase *FindTarget(const TArray<ECharacterType>&InIgnoreType = TArray<ECharacterType>(),ARouLikeCharacterBase* InMyPawn,float InRange=500.f);

	ECharacterType GetCharacterType(int32 InCharacterID);
}
