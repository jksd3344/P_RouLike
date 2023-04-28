#include "RoulikeWenponSingleHand.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

ARoulikeWenponSingleHand::ARoulikeWenponSingleHand()
{

}

void ARoulikeWenponSingleHand::AttachWeapons(USkeletalMeshComponent* StaticMeshComp)
{
	Super::AttachWeapons(StaticMeshComp);
	
	AttachToComponent(StaticMeshComp,FAttachmentTransformRules::KeepRelativeTransform,TEXT("LhandSocket"));
}


void ARoulikeWenponSingleHand::ReplaceVenpon()
{
	Super::ReplaceVenpon();
}

