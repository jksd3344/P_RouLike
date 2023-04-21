#include "P_RouLikeGameState.h"


FCharacterSkillTable* AP_RouLikeGameState::GetCharacterSkillTable(const FName& InSkillKey, int32 InCharacterTableID)
{
	if (TArray<FCharacterSkillTable*>* InSkillTable = GetTables(CharacterSkillTablePtr,CharacterSkillTables,TEXT("CharacterTable")))
	{
		if (FCharacterSkillTable **InFoundSkillTable = InSkillTable->FindByPredicate([&](const FCharacterSkillTable* InSkillTable)
		{
			if (InSkillTable->ID==InCharacterTableID)
			{
				return InSkillTable->GameplayAbility.GetDefaultObject()->AbilityTags == FGameplayTagContainer(FGameplayTag::RequestGameplayTag(InSkillKey));
			}

			return false;
		}))
		{
			return *InFoundSkillTable;
		}
	}
	return NULL;
}

TArray<FCharacterSkillTable*>* AP_RouLikeGameState::GetCharacterSkillTables()
{
	return GetTables(CharacterSkillTablePtr,CharacterSkillTables,TEXT("CharacterSkill"));
}

FCharacterAttributeTable* AP_RouLikeGameState::GetCharacterAttributeTable(int32 InCharacterTableID)
{
	return GetTable(InCharacterTableID,CharacterAttributePtr,CharacterAttribute,TEXT("AttributeTables"));
}

TArray<FCharacterAttributeTable*>* AP_RouLikeGameState::GetCharacterAttributeTables()
{
	return GetTables(CharacterAttributePtr,CharacterAttribute,TEXT("AttributeTables"));
}
