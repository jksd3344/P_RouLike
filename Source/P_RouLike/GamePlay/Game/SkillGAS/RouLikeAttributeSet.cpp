
#include "RouLikeAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"
#include "P_RouLike/GamePlay/Game/Character/Core/RouLikeCharacterBase.h"

URouLikeAttributeSet::URouLikeAttributeSet()
	:Health(100.f),MaxHealth(100.f),Damage(0.f)
{
	
}

void URouLikeAttributeSet::RegistrationProperties()
{
	
}

bool URouLikeAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	return Super::PreGameplayEffectExecute(Data);
	
}

void URouLikeAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	//��ȡ��ǩ
	const FGameplayTagContainer& SourceTagContainer = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();
	
	/*��ȡĿ��*/
	ARouLikeCharacterBase* Target = Data.Target.AbilityActorInfo.IsValid() ? Cast<ARouLikeCharacterBase>(Data.Target.AbilityActorInfo->AvatarActor) : NULL;
	
	/*��ȡ����˺�*/
	float Magnitude = 0.f;
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive)
	{
		Magnitude = Data.EvaluatedData.Magnitude;
	}

	/*��ȡcharacter*/
	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* SourceAbilitySystemComponent = Context.GetOriginalInstigatorAbilitySystemComponent();
	auto GetSourceCharacter = [&](AActor *& InSourceActor,ARouLikeCharacterBase *& InSourceCharacter)
	{
		if (Target)
		{
			InSourceActor=SourceAbilitySystemComponent->AbilityActorInfo->AvatarActor.Get();
			AController* SourceController = SourceAbilitySystemComponent->AbilityActorInfo->PlayerController.Get();
			if (SourceController==NULL&& InSourceActor!=NULL)
			{
				if (APawn* InPawn = Cast<APawn>(InSourceActor))
				{
					SourceController = InPawn->GetController();
				}
			}
			if (SourceController)
			{
				InSourceCharacter  = Cast<ARouLikeCharacterBase>(SourceController->GetPawn());
			}else
			{
				InSourceCharacter  = Cast<ARouLikeCharacterBase>(InSourceActor);
			}
		}
	};
	
	/*�ж��ǲ���health*/
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		/*��ֹ���*/
		SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));

		if (Target)
		{
			ARouLikeCharacterBase* SourceCharacter = NULL;
			AActor* SourceActor = NULL;
			GetSourceCharacter(SourceActor,SourceCharacter);

			Target->HandleHealth(SourceCharacter, SourceActor, SourceTagContainer, Magnitude);
		}
	}
}

void URouLikeAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(URouLikeAttributeSet, Health);
	DOREPLIFETIME(URouLikeAttributeSet, MaxHealth);
}

void URouLikeAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URouLikeAttributeSet, Health, OldValue);
}

void URouLikeAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URouLikeAttributeSet, MaxHealth, OldValue);
}

void URouLikeAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URouLikeAttributeSet, Damage, OldValue);
}
