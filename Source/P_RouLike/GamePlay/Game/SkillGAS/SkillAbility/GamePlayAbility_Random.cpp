#include "GamePlayAbility_Random.h"
#include "P_RouLike/GamePlay/Game/Character/Core/RouLikeCharacterBase.h"

void UGamePlayAbility_Random::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo,
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);


	if (!CommitAbilityCooldown(Handle,ActorInfo,ActivationInfo,true))
	{
		return;
	}

	if (ARouLikeCharacterBase* InCharacterBase = Cast<ARouLikeCharacterBase>(ActorInfo->OwnerActor))
	{
		if (PlayMontage(*FString::FromInt(FMath::RandRange(0,GetCompositeSectionsNumber()-1))))
		{

		}
	}
}
