#include "AnimNotify_CombatReset.h"
#include "P_RouLike/GamePlay/Common/ComBat/CombatInterface/CombatInterface.h"


UAnimNotify_CombatReset::UAnimNotify_CombatReset()
{
	
}

void UAnimNotify_CombatReset::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	//如果动画在这里之前切换就运行不到这里，就不会触发
	if (ICombatInterface* InSimpleCombatInterface=Cast<ICombatInterface>(MeshComp->GetOuter()))
	{
		InSimpleCombatInterface->CombatReset();
	}
}

FString UAnimNotify_CombatReset::GetNotifyName_Implementation() const
{
	return Super::GetNotifyName_Implementation();
}
