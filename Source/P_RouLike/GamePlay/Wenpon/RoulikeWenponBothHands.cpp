#include "RoulikeWenponBothHands.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

ARoulikeWenponBothHands::ARoulikeWenponBothHands()
{

}

void ARoulikeWenponBothHands::AttachWeapons(const USkeletalMeshComponent* StaticMeshComp)
{
	Super::AttachWeapons(StaticMeshComp);
}

void ARoulikeWenponBothHands::RegisterSkillToFightComponent()
{
	if (ARouLikeCharacter* InCharacter = Cast<ARouLikeCharacter>(GetOwner()))
	{
		//InCharacter->GetFightComponent()->RegisterComboAttack();
	}
}

void ARoulikeWenponBothHands::ReplaceVenpon()
{
	Super::ReplaceVenpon();
}

