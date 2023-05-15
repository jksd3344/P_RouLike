#include "AN_ChageCheck.h"

#include "P_RouLike/GamePlay/Common/ComBat/Hit/Core/HitCollisionBase.h"
#include "P_RouLike/GamePlay/Common/ComBat/Hit/HitType/HitCollisionBox.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

UAN_ChageCheck::UAN_ChageCheck()
	:Super()
{

}

void UAN_ChageCheck::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	if (ARouLikeCharacter* MyCharacter = Cast<ARouLikeCharacter>(MeshComp->GetOwner()))
	{
		
	}
}

FString UAN_ChageCheck::GetNotifyName_Implementation() const
{
	return Super::GetNotifyName_Implementation();
}



