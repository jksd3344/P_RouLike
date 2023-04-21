#include "GamePlayAbility_Hit.h"
#include "P_RouLike/GamePlay/Game/Character/Core/RouLikeCharacterBase.h"

void UGamePlayAbility_Hit::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if (!CommitAbility(Handle, ActorInfo, ActivationInfo))
	{
		return;
	}

	if (ARouLikeCharacterBase* InCharacterBase = Cast<ARouLikeCharacterBase>(ActorInfo->OwnerActor))
	{
		if (PlayMontage(*FString::FromInt(InCharacterBase->GetHitID())))
		{
			
		}
	}
}
