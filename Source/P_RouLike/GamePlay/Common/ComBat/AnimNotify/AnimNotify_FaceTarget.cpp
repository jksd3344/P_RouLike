#include "AnimNotify_FaceTarget.h"

#include "P_RouLike/GamePlay/Common/ComBat/CombatInterface/CombatInterface.h"

UAnimNotify_FaceTarget::UAnimNotify_FaceTarget()
{
}

void UAnimNotify_FaceTarget::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
	const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);
	if (ICombatInterface *InSimpleCombatInterface = Cast<ICombatInterface>(MeshComp->GetOuter()))
	{		
		if (AActor* InTarget = InSimpleCombatInterface->GetTarget())
		{
			if (AActor* InThis = Cast<AActor>(MeshComp->GetOuter()))
			{
				FRotator FaceRot = FRotationMatrix::MakeFromX(InTarget->GetActorLocation() - InThis->GetActorLocation()).Rotator();
				
				InThis->SetActorRotation(FaceRot);
			}
		}
	}
}
