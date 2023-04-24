#include "GamePlayAbilityCore.h"
#include "AbilitySystemComponent.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/GamePlayAbilityType.h"

UGamePlayAbilityCore::UGamePlayAbilityCore()
{
	
}

void UGamePlayAbilityCore::OnCompleted()
{
	K2_OnCompleted();
}

void UGamePlayAbilityCore::OnBlendOut()
{
	K2_OnBlendOut();
}

void UGamePlayAbilityCore::OnInterrupted()
{
	K2_OnInterrupted();
}

void UGamePlayAbilityCore::OnCancelled()
{
	K2_OnCancelled();
}

UAbilityTask_PlayMontageAndWait* UGamePlayAbilityCore::PlayMontage(FName StartSection)
{
	return CreatePlayMontageAndWaitProxy(NAME_None,MontageToPlay, 1.f,StartSection);
}

UAbilityTaskEvent* UGamePlayAbilityCore::CreatePlayMontageAndWaitProxy(FName TaskInstanceName,
	UAnimMontage* InMontageToPlay, float Rate, FName StartSection, bool bStopWhenAbilityEnds,
	float AnimRootMotionTranslationScale, float StartTimeSeconds)
{
	if (UAbilityTaskEvent* InWait = UAbilityTaskEvent::CreateAbilityTaskEventProxy(
		this,
		TaskInstanceName,
		InMontageToPlay,
		AbilityTags,
		Rate,
		StartSection,
		bStopWhenAbilityEnds,
		AnimRootMotionTranslationScale,
		StartTimeSeconds))
	{
		InWait->OnBlendOut.AddDynamic(this,&UGamePlayAbilityCore::OnBlendOut);
		InWait->OnCompleted.AddDynamic(this,&UGamePlayAbilityCore::OnCompleted);
		InWait->OnInterrupted.AddDynamic(this,&UGamePlayAbilityCore::OnInterrupted);
		InWait->OnCancelled.AddDynamic(this,&UGamePlayAbilityCore::OnCancelled);

		/*通过代理将返回注册回来*/
		InWait->DamageEventReceived.AddDynamic(this,&UGamePlayAbilityCore::OnDamageGameplayEvent);
		InWait->Activate();
        
		return InWait;
	}
	return nullptr;
}

void UGamePlayAbilityCore::OnDamageGameplayEvent(FGameplayTag InGameplayTag, FGameplayEventData Payload)
{
	//伤害通知 为什么要在这里计算，因为这里保存了技能的基本属性，可以触发attributeset中的post函数
	if (FRouLikeGameplayEffects* InEffect =  EffectMap.Find(InGameplayTag))
	{
		FRouLikeGameplayEffectSpec GameplayEffectSpec;

		/*这个是用来注册目标的*/
		FGameplayAbilityTargetData_ActorArray* NewTargetData_ActorArray = new FGameplayAbilityTargetData_ActorArray();
		NewTargetData_ActorArray->TargetActorArray.Add(const_cast<AActor*>(Payload.Target.Get()));
		GameplayEffectSpec.TargetHandleData.Add(NewTargetData_ActorArray);


		/*添加每一个effect*/
		for (auto&Tmp:InEffect->TargetEffectClasses)
		{
			FGameplayEffectSpecHandle NewHandle =GetAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(Tmp,1,MakeEffectContext(CurrentSpecHandle,CurrentActorInfo));

			if (NewHandle.IsValid())
			{
				FGameplayAbilitySpec* AbilitySpec = GetAbilitySystemComponentFromActorInfo()->FindAbilitySpecFromHandle(CurrentSpecHandle);
				ApplyAbilityTagsToGameplayEffectSpec(*NewHandle.Data.Get(), AbilitySpec);
				if (AbilitySpec)
				{
					NewHandle.Data->SetByCallerTagMagnitudes = AbilitySpec->SetByCallerTagMagnitudes;
					GameplayEffectSpec.TargetEffectSpecs.Add(NewHandle);
				}
			}
		}

		for (auto &Tmp:GameplayEffectSpec.TargetEffectSpecs)
		{
			/*这里调用注册到Attributeset中的 PostGameplayEffectExecute */
			TArray<FActiveGameplayEffectHandle> ActiveGameplayEffectHandles = K2_ApplyGameplayEffectSpecToTarget(Tmp, GameplayEffectSpec.TargetHandleData);
		}
	}
}

int32 UGamePlayAbilityCore::GetCompositeSectionsNumber()
{
	if (MontageToPlay)
	{
		return MontageToPlay->CompositeSections.Num();
	}
	return 0;
}
