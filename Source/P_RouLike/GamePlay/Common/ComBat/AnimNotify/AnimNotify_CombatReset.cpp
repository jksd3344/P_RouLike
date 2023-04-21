#include "AnimNotify_CombatReset.h"
#include "P_RouLike/GamePlay/Common/ComBat/CombatInterface/CombatInterface.h"


UAnimNotify_CombatReset::UAnimNotify_CombatReset()
{
	
}

void UAnimNotify_CombatReset::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	//�������������֮ǰ�л������в�������Ͳ��ᴥ��
	if (ICombatInterface* InSimpleCombatInterface=Cast<ICombatInterface>(MeshComp->GetOuter()))
	{
		InSimpleCombatInterface->CombatReset();
	}
}

FString UAnimNotify_CombatReset::GetNotifyName_Implementation() const
{
	return Super::GetNotifyName_Implementation();
}
