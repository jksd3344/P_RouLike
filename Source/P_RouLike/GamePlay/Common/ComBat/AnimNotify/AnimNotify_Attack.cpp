#include "AnimNotify_Attack.h"

#include "P_RouLike/GamePlay/Common/ComBat/Hit/Core/HitCollisionBase.h"
#include "P_RouLike/GamePlay/Common/ComBat/Hit/HitType/HitCollisionBox.h"

UAnimNotify_Attack::UAnimNotify_Attack()
	:Super()
{
	HitObjectClass=AHitCollisionBox::StaticClass();
	LiftTime=4.f;
	BoxExtent = FVector(32.f);
	InSocketName = TEXT("OpenFile");
}

void UAnimNotify_Attack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation,EventReference);
	
	if (AActor* InCharacter = Cast<AActor>(MeshComp->GetOuter()))
	{
		FVector  ComponentLocation = MeshComp->GetSocketLocation(InSocketName);
		FRotator ComponentRotation = MeshComp->GetSocketRotation(InSocketName);

		/*��ײ�����Լ�*/
		FActorSpawnParameters ActorSpawnParameters;
		ActorSpawnParameters.Instigator = Cast<APawn>(InCharacter);

		if (InCharacter->GetWorld())
		{
			if (!bCanCreateOnClient||InCharacter->GetWorld()->IsServer())
			{
				/*������ײ��*/
				if (AHitCollisionBase* HitCollision = InCharacter->GetWorld()->SpawnActor<AHitCollisionBase>(HitObjectClass,ComponentLocation,ComponentRotation,ActorSpawnParameters))
				{
					HitCollision->SetHitID(HitID);
					if (HitCollision->GetHitDamage())
					{
						/*������������*/
						HitCollision->SetLifeSpan(LiftTime);
						FVector RelativeLocation = HitCollision->GetHitDamage()->GetRelativeLocation();
						HitCollision->SetHitDamageRelativePosition(RelativeLocation + RelativeOffsetLocation);
						if (AHitCollisionBox* InBox = Cast<AHitCollisionBox>(HitCollision))
						{
							InBox->SetBoxExtent(BoxExtent);
						}
					}

					/*���û��ע�򲻰󶨵�������*/
					if (InSocketName!=NAME_None)
					{
						HitCollision->AttachToComponent(MeshComp,FAttachmentTransformRules::SnapToTargetNotIncludingScale,InSocketName);
					}
				}
			}
		}
	}
}

FString UAnimNotify_Attack::GetNotifyName_Implementation() const
{
	return Super::GetNotifyName_Implementation();
}


FLinearColor UAnimNotify_Attack::GetEditorColor()
{
	return FLinearColor::Red;
}
