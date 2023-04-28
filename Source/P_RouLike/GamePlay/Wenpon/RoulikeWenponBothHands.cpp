#include "RoulikeWenponBothHands.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

ARoulikeWenponBothHands::ARoulikeWenponBothHands()
{

}

void ARoulikeWenponBothHands::AttachWeapons(USkeletalMeshComponent* StaticMeshComp)
{
	Super::AttachWeapons(StaticMeshComp);
	AttachToComponent(StaticMeshComp,FAttachmentTransformRules::KeepRelativeTransform,TEXT("LhandSocket"));
}



void ARoulikeWenponBothHands::ReplaceVenpon()
{
	Super::ReplaceVenpon();
}

