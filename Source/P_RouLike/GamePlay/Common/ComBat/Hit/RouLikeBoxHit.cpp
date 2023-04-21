
#include "RouLikeBoxHit.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Components/BoxComponent.h"
#include "P_RouLike/GamePlay/Game/Character/Core/RouLikeCharacterBase.h"

ARouLikeBoxHit::ARouLikeBoxHit(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void ARouLikeBoxHit::HandleDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::HandleDamage(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	
	if (GetInstigator() != OtherActor)
	{
		/*��ȡ�Լ�*/
		if (ARouLikeCharacterBase* InOwer = Cast<ARouLikeCharacterBase>(GetInstigator()))
		{
			if (ARouLikeCharacterBase* InTarget = Cast<ARouLikeCharacterBase>(OtherActor))
			{
				if (!InTarget->IsDie())
				{
					if (InTarget->GetWorld()->IsServer())
					{
						/*ע��Ŀ���ܻ�id*/
						InTarget->SetHitID(GetHitID());

						//�������
						FGameplayEventData EventData;
						EventData.Instigator = GetInstigator();
						EventData.Target = InTarget;

						static const FName Player_State_Hit_Box_Name(TEXT("Character.State.Hit"));
						UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(GetInstigator(), FGameplayTag::RequestGameplayTag(Player_State_Hit_Box_Name), EventData);
						
					}
				}
			}
		}
	}
}


