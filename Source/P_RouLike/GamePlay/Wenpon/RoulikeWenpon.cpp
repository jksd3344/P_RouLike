#include "RoulikeWenpon.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

ARoulikeWenpon::ARoulikeWenpon()
{

}

void ARoulikeWenpon::RegisterSkillToFightComponent(const int32 WenponID,const FName& InKey)
{
	if (ARouLikeCharacter* InCharacter = Cast<ARouLikeCharacter>(GetOwner()))
	{
		InCharacter->GetFightComponent()->RepickRegisterComboAttack(WenponID,InKey);
	}
}