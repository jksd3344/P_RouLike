// Copyright (C) RenZhai.2020.All Rights Reserved.

#pragma once

#include "AbilitySystemComponent.h"
#include "RouLikeWenponAttributeSet.generated.h"


#define PROPERTY_FUNCTION_REGISTRATION(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class P_ROULIKE_API URouLikeWenponAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	URouLikeWenponAttributeSet();
	
	virtual void RegistrationProperties();
	virtual void GetLifetimeReplicatedProps(::TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, Category = "Lv", ReplicatedUsing = OnRep_Lv)
	FGameplayAttributeData Lv;
	PROPERTY_FUNCTION_REGISTRATION(URouLikeWenponAttributeSet,Lv)	
	
	UPROPERTY(BlueprintReadOnly, Category = "Experience", ReplicatedUsing = OnRep_Experience)
	FGameplayAttributeData Experience;
	PROPERTY_FUNCTION_REGISTRATION(URouLikeWenponAttributeSet,Experience)

	UPROPERTY(BlueprintReadOnly, Category = "MaxExperience", ReplicatedUsing = OnRep_MaxExperience)
	FGameplayAttributeData MaxExperience;
	PROPERTY_FUNCTION_REGISTRATION(URouLikeWenponAttributeSet,MaxExperience)
protected:
	UFUNCTION()
	virtual void OnRep_Experience(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_MaxExperience(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	virtual void OnRep_Lv(const FGameplayAttributeData& OldValue);
};

