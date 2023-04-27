#include "RoulikeWenponSingleHand.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

ARoulikeWenponSingleHand::ARoulikeWenponSingleHand()
{

}

void ARoulikeWenponSingleHand::AttachWeapons(const USkeletalMeshComponent* StaticMeshComp)
{
	Super::AttachWeapons(StaticMeshComp);
	
}

void ARoulikeWenponSingleHand::RegisterSkillToFightComponent()
{
	if (ARouLikeCharacter* InCharacter = Cast<ARouLikeCharacter>(GetOwner()))
	{
		//InCharacter->GetFightComponent()->RegisterComboAttack();
	}
}

void ARoulikeWenponSingleHand::ReplaceVenpon()
{
	Super::ReplaceVenpon();
}

