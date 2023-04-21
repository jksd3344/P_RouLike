#include "RouLikeAbilitySystemComponent.h"
#include "AbilitySystemGlobals.h"

URouLikeAbilitySystemComponent::URouLikeAbilitySystemComponent()
{
	
}

URouLikeAbilitySystemComponent* URouLikeAbilitySystemComponent::GetAbilitySystemComponentFromActor(const AActor* Actor,bool LookForComponent)
{
	return Cast<URouLikeAbilitySystemComponent>(UAbilitySystemGlobals::GetAbilitySystemComponentFromActor(Actor,LookForComponent));
};
