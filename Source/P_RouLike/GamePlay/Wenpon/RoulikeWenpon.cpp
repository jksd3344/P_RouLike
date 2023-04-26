#include "RoulikeWenpon.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

ARoulikeWenpon::ARoulikeWenpon()
{

}

void ARoulikeWenpon::RegisterSkillToFightComponent()
{
	if (ARouLikeCharacter* InCharacter = Cast<ARouLikeCharacter>(GetOwner()))
	{
		if (PropId!=INDEX_NONE)
		{
			InCharacter->GetFightComponent()->RepickRegisterComboAttack(TEXT("Character.Attack.NormalAttack"),PropId);
		}
	}
}
