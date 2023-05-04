// Copyright Epic Games, Inc. All Rights Reserved.

#include "RouLikeCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/RouLikeWenponAttributeSet.h"
#include "P_RouLike/UI/Game/Character/UI_CharacterBarWidget.h"


ARouLikeCharacterBase::ARouLikeCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
	FightComponents = CreateDefaultSubobject<UFightComponent>(TEXT("FightComponents"));
	FightComponents->SetIsReplicated(true);
	
	AbilitySystemComponent = CreateDefaultSubobject<URouLikeAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	Widget->SetupAttachment(RootComponent);
	Widget->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	
	LvAttributeSet = CreateDefaultSubobject<URouLikeWenponAttributeSet>(TEXT("LvAttributeSet"));
	AttributeSet = CreateDefaultSubobject<URouLikeAttributeSet>(TEXT("AttributeSet"));
}

void ARouLikeCharacterBase::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
	
    if (GetLocalRole()!=ENetRole::ROLE_Authority)
    {
    	if (GetLocalRole() != ENetRole::ROLE_AutonomousProxy)
    	{
    		if (UUI_CharacterBarWidget* InWidget = Cast<UUI_CharacterBarWidget>(GetWidget()))
    		{
    			InWidget->SetHealth(AttributeSet->GetHealth()/AttributeSet->GetMaxHealth());
    		}
    	}
    }
}

FRouLikeCombat* ARouLikeCharacterBase::GetCombatInfo()
{
	return GetFightComponent()->GetCombatInfo();
}

void ARouLikeCharacterBase::ComboAttack(const FName& InKey)
{
	NormalAttack(InKey);
}

void ARouLikeCharacterBase::NormalAttack(const FName& InKey)
{
	GetFightComponent()->Attack(InKey);
}

bool ARouLikeCharacterBase::IsDie()
{
	if (AttributeSet)
	{
		return AttributeSet->GetHealth() <= 0.f;
	}
	
	return true;
}

void ARouLikeCharacterBase::SetHitID(int32 InNewID)
{
	FightComponents->HitID = InNewID;
}

const int32 ARouLikeCharacterBase::GetHitID() const
{
	return FightComponents->HitID;
}

void ARouLikeCharacterBase::PlayHit()
{
	GetFightComponent()->Hit();
}

void ARouLikeCharacterBase::PlayDie()
{
	GetFightComponent()->Die();
}

void ARouLikeCharacterBase::HandleHealth(ARouLikeCharacterBase* InstigatorPawn, AActor* DamageCauser,const FGameplayTagContainer& InTags, float InNewValue, bool bPlayHit)
{
	GetFightComponent()->HandleHealth(InstigatorPawn, DamageCauser,InTags, InNewValue,bPlayHit);
}

void ARouLikeCharacterBase::AnimSignal(int32 InSignal)
{
	K2_AnimSignal(InSignal);

	if (InSignal==7)
	{
		DieIndex=0;
	}else
	{
		DieIndex=1;
	}
}

UWidget* ARouLikeCharacterBase::GetWidget()
{
	if (Widget)
	{
		return Cast<UWidget>(Widget->GetUserWidgetObject());
	}
	return NULL;
}

void ARouLikeCharacterBase::IsHideWidget(bool IsHide)
{
	if (UWidget* InWidget = GetWidget())
	{
		if (IsHide)
		{
			InWidget->SetVisibility(ESlateVisibility::Collapsed);
		}else
		{
			InWidget->SetVisibility(ESlateVisibility::Visible);
		}

	}
}

void ARouLikeCharacterBase::RewardEffect(float InNewLevel, TSubclassOf<UGameplayEffect> InNewReward,
	TFunction<void()> InFun)
{
	GetFightComponent()->RewardEffect(InNewLevel,InNewReward,InFun);
}

float ARouLikeCharacterBase::GetCharacterLevel()
{
	return LvAttributeSet->GetLv();
}

bool ARouLikeCharacterBase::IsUpdateLevel()
{
	if (LvAttributeSet)
	{
		return LvAttributeSet->GetExperience()>=LvAttributeSet->GetMaxExperience();
	}
	return false;
}


void ARouLikeCharacterBase::UpdateCharacterAttribute_Implementation(const FCharacterAttributeTable& CharacterAttributeTable)
{
	
}

void ARouLikeCharacterBase::CombatReset()
{
	GetFightComponent()->Reset();
}

