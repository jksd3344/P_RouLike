#include "FightComponent.h"
#include "P_RouLike/GamePlay/Game/Character/Core/RouLikeCharacterBase.h"
#include "P_RouLike/GamePlay/Game/GameWorld/P_RouLikePlayerState.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/Core/GamePlayAbilityCore.h"


UFightComponent::UFightComponent()
{
}

void UFightComponent::BeginPlay()
{
	Super::BeginPlay();

	if (RouLikeCharacterBase.IsValid())
	{
		AbilitySystemComponent = Cast<URouLikeAbilitySystemComponent>(RouLikeCharacterBase->GetAbilitySystemComponent());
		const FName InKey=TEXT("Character.Attack.NormalAttack");
		if (RouLikeCharacterBase->GetLocalRole() == ENetRole::ROLE_Authority)
		{
			//测试
			RouLikeGameplayAbility(TEXT("Character.Attack.NormalAttack"));
			RouLikeGameplayAbility(TEXT("Character.State.Hit"));
			RouLikeGameplayAbility(TEXT("Character.State.Die"));

			//只能服务器注册 客户端不能注册
			AbilitySystemComponent->InitAbilityActorInfo(RouLikeCharacterBase.Get(), RouLikeCharacterBase.Get());
		}
		RegisterComboAttack(CombatAttack, InKey);
	}
}

void UFightComponent::RepickRegisterComboAttack()
{
<<<<<<< HEAD
	if (AP_RouLikePlayerState* InPlayState = GetWorld()->GetFirstPlayerController()->GetPlayerState<AP_RouLikePlayerState>())
	{
		if (FSlotAttributeTable* AttributeTable = InPlayState->GetAttributeTable(WenponID))
		{
			if (Skills.Contains(InKey))
			{
				FGameplayAbilitySpecHandle AbilitySpecHandle = AddAbility(*AttributeTable->GameCombatAbility);
				Skills[InKey] = AbilitySpecHandle;

				RegisterComboAttack(CombatAttack, TEXT("Character.Attack.NormalAttack"));

				
			}
		}
	}
=======
	
>>>>>>> parent of 83bd752 (xin 2023 04 26)
}

void UFightComponent::RouLikeGameplayAbility(const FName& InKey)
{
	if (AP_RouLikePlayerState* InGameState = GetWorld()->GetFirstPlayerController()->GetPlayerState<AP_RouLikePlayerState>())
	{
		if (FCharacterSkillTable* InSkillTable = InGameState->GetCharacterSkillTable(InKey,RouLikeCharacterBase->GetID()))
		{
			FGameplayAbilitySpecHandle  AbilitySpecHandle = AddAbility(*InSkillTable->GameplayAbility);
			Skills.Add(InKey, AbilitySpecHandle);
		}
	}
}

FGameplayAbilitySpecHandle UFightComponent::AddAbility(TSubclassOf<UGameplayAbility> InNewAbility)
{
	if (IsValid(InNewAbility)&&AbilitySystemComponent.IsValid())
	{
		return AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(InNewAbility));
	}
	return FGameplayAbilitySpecHandle();
}

bool UFightComponent::Attack(const FName& Index)
{
	return TryActivateAbility(Index, Skills);
}

bool UFightComponent::TryActivateAbility(const FName& InTagName, const TMap<FName, FGameplayAbilitySpecHandle>& InMap)
{
	if (AbilitySystemComponent.IsValid())
	{
		if (const FGameplayAbilitySpecHandle* Handle = InMap.Find(InTagName))
		{
			AbilitySystemComponent->TryActivateAbility(*Handle);
			return true;
		}
	}
	return false;
}

void UFightComponent::RegisterComboAttack(FRouLikeCombat& InComboAttack, const FName& Key)
{
	InComboAttack.Character = RouLikeCharacterBase.Get();
	InComboAttack.ComboKey = Key;
	if (UGamePlayAbilityCore* GameplayAbility = GetGameplayAbility(Key))
	{
		InComboAttack.MaxIndex = GameplayAbility->GetCompositeSectionsNumber();
	}
	else
	{
		InComboAttack.MaxIndex = 4;
	}
}


UGamePlayAbilityCore* UFightComponent::GetGameplayAbility(const FName& InKey)
{
	if (FGameplayAbilitySpecHandle* InHandle = Skills.Find(InKey))
	{
		if (InHandle->IsValid())
		{
			if (FGameplayAbilitySpec* Spec = AbilitySystemComponent->FindAbilitySpecFromHandle(*InHandle))
			{
				return Cast<UGamePlayAbilityCore>(Spec->Ability);
			}
		}
	}
	return nullptr;
}

void UFightComponent::Hit()
{
	TryActivateAbility(TEXT("Character.State.Hit"), Skills);
}

void UFightComponent::Die()
{
	TryActivateAbility(TEXT("Character.State.Die"),Skills);
}

void UFightComponent::HandleHealth(ARouLikeCharacterBase* InstigatorPawn, AActor* DamageCauser,const FGameplayTagContainer& InTags, float InNewValue, bool bPlayHit)
{
	if (RouLikeCharacterBase.IsValid())
	{
		if (RouLikeCharacterBase->IsDie())
		{
			RouLikeCharacterBase->PlayDie();
		}else
		{
			if (RouLikeCharacterBase->GetHitID()!=INDEX_NONE)
			{
				/*受击*/
				RouLikeCharacterBase->PlayHit();
			}
		}
	}
}

void UFightComponent::Press()
{
	CombatAttack.Press();
}

void UFightComponent::Released()
{
	CombatAttack.Released();
}

void UFightComponent::Reset()
{
	CombatAttack.Reset();
}
