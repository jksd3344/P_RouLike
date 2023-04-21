#include "GamePlayAbilitySkill.h"

void UGamePlayAbilitySkill::OnCompleted()
{
	Super::OnCompleted();
	//Ω· ¯GA
	EndAbility(CurrentSpecHandle,CurrentActorInfo,CurrentActivationInfo,true,false);
}

void UGamePlayAbilitySkill::OnBlendOut()
{
	Super::OnBlendOut();
	EndAbility(CurrentSpecHandle,CurrentActorInfo,CurrentActivationInfo,true,false);
}

void UGamePlayAbilitySkill::OnInterrupted()
{
	Super::OnInterrupted();
	EndAbility(CurrentSpecHandle,CurrentActorInfo,CurrentActivationInfo,true,false);
}

void UGamePlayAbilitySkill::OnCancelled()
{
	Super::OnCancelled();
	EndAbility(CurrentSpecHandle,CurrentActorInfo,CurrentActivationInfo,true,false);
}
