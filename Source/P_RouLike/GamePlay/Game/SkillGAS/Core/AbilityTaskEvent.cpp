#include "AbilityTaskEvent.h"
#include "AbilitySystemGlobals.h"
#include "AbilitySystemComponent.h"

UAbilityTaskEvent::UAbilityTaskEvent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	
}

UAbilityTaskEvent* UAbilityTaskEvent::CreateAbilityTaskEventProxy(UGameplayAbility* OwningAbility,
	FName TaskInstanceName, UAnimMontage* MontageToPlay, FGameplayTagContainer InEventTags, float Rate,
	FName StartSection, bool bStopWhenAbilityEnds, float AnimRootMotionTranslationScale, float StartTimeSeconds)
{
	UAbilitySystemGlobals::NonShipping_ApplyGlobalAbilityScaler_Rate(Rate);

	UAbilityTaskEvent* MyObj = NewAbilityTask<UAbilityTaskEvent>(OwningAbility, TaskInstanceName);
	MyObj->MontageToPlay = MontageToPlay;
	MyObj->Rate = Rate;
	MyObj->StartSection = StartSection;
	MyObj->AnimRootMotionTranslationScale = AnimRootMotionTranslationScale;
	MyObj->bStopWhenAbilityEnds = bStopWhenAbilityEnds;
	MyObj->StartTimeSeconds = StartTimeSeconds;
	MyObj->EventTags = InEventTags;

	return MyObj;
}

void UAbilityTaskEvent::Activate()
{
	if (Ability == nullptr)
	{
		return;
	}

	if (AbilitySystemComponent.IsValid())
	{
		const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
		UAnimInstance* AnimInstance = ActorInfo->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AbilitySystemComponent->AddGameplayEventTagContainerDelegate(
				FGameplayTagContainer(),//这里放空是为了让buf可以激活
				FGameplayEventTagMulticastDelegate::FDelegate::CreateUObject(this,&UAbilityTaskEvent::OnDamageGameplayEvent));
		}
	}
	Super::Activate();
}

void UAbilityTaskEvent::OnDamageGameplayEvent(FGameplayTag InGameplayTag, const FGameplayEventData* Payload)
{
	if (ShouldBroadcastAbilityTaskDelegates())
	{
		FGameplayEventData EventData = *Payload;
		EventData.EventTag = InGameplayTag;

		DamageEventReceived.Broadcast(InGameplayTag, EventData);
	}
}

void UAbilityTaskEvent::OnDestroy(bool bInOwnerFinished)
{
	if (AbilitySystemComponent.IsValid())
	{
		AbilitySystemComponent->RemoveGameplayEventTagContainerDelegate(EventTags,DamageEventHandle);
	}
	Super::OnDestroy(bInOwnerFinished);
}
