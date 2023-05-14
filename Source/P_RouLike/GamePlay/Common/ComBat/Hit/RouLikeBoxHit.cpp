
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
		/*获取自己*/
		if (ARouLikeCharacterBase* InOwer = Cast<ARouLikeCharacterBase>(GetInstigator()))
		{
			if (ARouLikeCharacterBase* InTarget = Cast<ARouLikeCharacterBase>(OtherActor))
			{
				if (!InTarget->IsDie())
				{
					if (InTarget->GetWorld()->IsServer())
					{
						/*注册目标受击id*/
						InTarget->SetHitID(GetHitID());

						//参数相关
						FGameplayEventData EventData;
						EventData.Instigator = InOwer;
						EventData.Target = InTarget;

						static const FName Player_State_Hit_Box_Name(TEXT("Character.State.Hit"));
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Successed Produce NPC")));
						UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(InOwer, FGameplayTag::RequestGameplayTag(Player_State_Hit_Box_Name), EventData);
						
					}
				}
			}
		}
	}
}




