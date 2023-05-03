
#include "RouLikeWenponAttributeSet.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

URouLikeWenponAttributeSet::URouLikeWenponAttributeSet()
	:Lv(0),Experience(0),MaxExperience(0)
{
	
}

void URouLikeWenponAttributeSet::RegistrationProperties()
{
	
}

bool URouLikeWenponAttributeSet::PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data)
{
	Super::PreGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute ==GetExperienceAttribute())
	{
		float NewEx = GetExperience();
		if (NewEx>GetMaxExperience())
		{
			NewEx -=GetMaxExperience();
			SetExperience(NewEx);
		}
	}
	return true;
}

void URouLikeWenponAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	float Magnitude = 0.0f;
	if (Data.EvaluatedData.ModifierOp==EGameplayModOp::Type::Additive)
	{
		Magnitude = Data.EvaluatedData.Magnitude;
	}

	if (Data.EvaluatedData.Attribute == GetExperienceAttribute())
	{
		float NewExpValue = Magnitude + GetExperience()+100.f;
		SetExperience(NewExpValue);
	}
}

void URouLikeWenponAttributeSet::OnRep_Experience(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URouLikeWenponAttributeSet, Lv, OldValue);
}

void URouLikeWenponAttributeSet::OnRep_MaxExperience(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URouLikeWenponAttributeSet, Experience, OldValue);
}

void URouLikeWenponAttributeSet::OnRep_Lv(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(URouLikeWenponAttributeSet, MaxExperience, OldValue);
}

void URouLikeWenponAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(URouLikeWenponAttributeSet, Lv);
	DOREPLIFETIME(URouLikeWenponAttributeSet, Experience);
	DOREPLIFETIME(URouLikeWenponAttributeSet, MaxExperience);
}
