#include "RouLikeAnimInstanceBase.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

URouLikeAnimInstanceBase::URouLikeAnimInstanceBase()
{
}

void URouLikeAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (ARouLikeCharacter* InCharacterBase = Cast<ARouLikeCharacter>(TryGetPawnOwner()))
	{
		bDeath   = InCharacterBase->IsDie();
		DieIndex = InCharacterBase->GetDieIndex();
	}
}
