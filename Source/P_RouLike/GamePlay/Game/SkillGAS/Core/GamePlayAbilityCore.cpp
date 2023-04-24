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

		/*ͨ����������ע�����*/
		InWait->DamageEventReceived.AddDynamic(this,&UGamePlayAbilityCore::OnDamageGameplayEvent);
		InWait->Activate();
        
		return InWait;
	}
	return nullptr;
}

void UGamePlayAbilityCore::OnDamageGameplayEvent(FGameplayTag InGameplayTag, FGameplayEventData Payload)
{
	//�˺�֪ͨ ΪʲôҪ��������㣬��Ϊ���ﱣ���˼��ܵĻ������ԣ����Դ���attributeset�е�post����
	if (FRouLikeGameplayEffects* InEffect =  EffectMap.Find(InGameplayTag))
	{
		FRouLikeGameplayEffectSpec GameplayEffectSpec;

		/*���������ע��Ŀ���*/
		FGameplayAbilityTargetData_ActorArray* NewTargetData_ActorArray = new FGameplayAbilityTargetData_ActorArray();
		NewTargetData_ActorArray->TargetActorArray.Add(const_cast<AActor*>(Payload.Target.Get()));
		GameplayEffectSpec.TargetHandleData.Add(NewTargetData_ActorArray);


		/*���ÿһ��effect*/
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
			/*�������ע�ᵽAttributeset�е� PostGameplayEffectExecute */
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
