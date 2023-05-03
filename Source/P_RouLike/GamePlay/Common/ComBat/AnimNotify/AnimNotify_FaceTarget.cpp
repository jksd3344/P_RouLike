#include "AnimNotify_FaceTarget.h"

#include "P_RouLike/GamePlay/Common/ComBat/CombatInterface/CombatInterface.h"
#include "P_RouLike/GamePlay/Game/Character/Core/RouLikeCharacterBase.h"

UAnimNotify_FaceTarget::UAnimNotify_FaceTarget()
{
	
}

void UAnimNotify_FaceTarget::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation,EventReference);

	if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(MeshComp->GetOuter()))
	{
		if (AActor* InTarget =CombatInterface->GetTarget())
		{
			if (AActor* InThis = Cast<ARouLikeCharacterBase>(MeshComp->GetOuter()))
			{
				FRotator FaceRot = FRotationMatrix::MakeFromX(InTarget->GetActorLocation()-InThis->GetActorLocation()).Rotator();

				InThis->SetActorRotation(FaceRot);
			}
		}
	}
}
