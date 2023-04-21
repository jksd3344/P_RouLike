#include "AnimNotifyState_Combat.h"

#include "P_RouLike/GamePlay/Common/ComBat/CombatType.h"
#include "P_RouLike/GamePlay/Common/ComBat/CombatInterface/CombatInterface.h"

void UAnimNotifyState_Combat::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	if (MeshComp->GetOwner()&&MeshComp->GetOwner()->GetWorld())
	{
		if (ICombatInterface* InCharacter = Cast<ICombatInterface>(MeshComp->GetOwner()))
		{
			//设置短按未false,这样按下在设为true,否则不触发
			InCharacter->GetCombatInfo()->bShortPress=false;
			//下标+1
			InCharacter->GetCombatInfo()->UpdateCombatIndex();
		}
	}
}

void UAnimNotifyState_Combat::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UAnimNotifyState_Combat::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	if (ICombatInterface* InCharacter = Cast<ICombatInterface>(MeshComp->GetOwner()))
	{
		//如果长按或者短按其中一个为True则可以执行下面的连击
		if (InCharacter->GetCombatInfo()->bLongPress||InCharacter->GetCombatInfo()->bShortPress)
		{
			InCharacter->ComboAttack(CombatKey);
		}
	}
}
