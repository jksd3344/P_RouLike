#include "P_RouLikePlayerState.h"

AP_RouLikePlayerState::AP_RouLikePlayerState()
{
}

void AP_RouLikePlayerState::BeginPlay()
{
	Super::BeginPlay();

	/*初始化创建十个格子*/
	for (int i =0;i<10;i++)
	{
		InitializeInventorySlot(InventorySlots);
	}
}

void AP_RouLikePlayerState::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AP_RouLikePlayerState::InitializeInventorySlot(TMap<int32,FRouLikeSlotData> In_InventorySlots)
{
	int32 InSlotID = FMath::RandRange(0,999999);
	if (!In_InventorySlots.Contains(InSlotID))
	{
		In_InventorySlots.Add(InSlotID,FRouLikeSlotData());
	}else
	{
		InitializeInventorySlot(In_InventorySlots);
	}
}


bool AP_RouLikePlayerState::IsExistInInventory(int32 InItemID)
{
	for(auto &Tmp:InventorySlots)
	{
		if (Tmp.Value.SlotID==InItemID)
		{
			if (Tmp.Value.Number<5)
			{
				return true;
			}
		}
	}
	return false;
}

bool AP_RouLikePlayerState::AddSlotToInventory(int32 InSlotID)
{
	if (FSlotTable* InSlotTable = GetSlotTable(InSlotID))
	{
		/*是否存在在背包*/
		bool IsExist = IsExistInInventory(InSlotID);
		/*是否是消耗品*/
		bool IsConsumables = InSlotTable->SlotType.Contains(ESlotPropType::SLOT_CONSUMABLES);


		auto AddSlot=[&]()->int32
		{
			for (auto &Tmp:InventorySlots)
			{
				if (Tmp.Value.SlotID!=INDEX_NONE)
				{
					if (IsConsumables&&!IsExist)
					{
						Tmp.Value.Number =1;
					}
					Tmp.Value.SlotICO = InSlotTable->SlotIcon;
					Tmp.Value.SlotID = InSlotTable->ID;
					return Tmp.Key;
					/*为什么只赋值id icon number,因为只在UI显示,不需要别的*/
				}
			}
			return INDEX_NONE;
		};

		int32 InInventoryID =INDEX_NONE;
		if (IsConsumables)
		{
			if (IsExist)
			{
				for (auto&Tmp:InventorySlots)
				{
					if (InSlotTable->ID==Tmp.Value.SlotID&&Tmp.Value.SlotID!=INDEX_NONE)
					{
						if (Tmp.Value.Number<5)
						{
							Tmp.Value.Number++;
							break;
						}
					}
				}
			}else
			{
				InInventoryID = AddSlot();
			}
		}else
		{
			InInventoryID = AddSlot();
		}

		if (InInventoryID!=INDEX_NONE)
		{
			/*添加装备的属性*/
			return true;
		}
	}

	return false;
}

void AP_RouLikePlayerState::DeleteSlotToInventory(int32 InSlotID)
{
	if (FRouLikeSlotData* InSlotData = GetInventorySlotData(InSlotID))
	{
		InventorySlots.Remove(InSlotID);
	}
}

FRouLikeSlotData* AP_RouLikePlayerState::GetInventorySlotData(int32 InInventoryID)
{
	if (InventorySlots.Contains(InInventoryID))
	{
		return &InventorySlots[InInventoryID];
	}
	return NULL;
}

FCharacterSkillTable* AP_RouLikePlayerState::GetCharacterSkillTable(const FName& InSkillKey, int32 InCharacterTableID)
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

TArray<FCharacterSkillTable*>* AP_RouLikePlayerState::GetCharacterSkillTables()
{
	return GetTables(CharacterSkillTablePtr,CharacterSkillTables,TEXT("CharacterSkill"));
}

FCharacterAttributeTable* AP_RouLikePlayerState::GetCharacterAttributeTable(int32 InCharacterTableID)
{
	return GetTable(InCharacterTableID,CharacterAttributePtr,CharacterAttribute,TEXT("AttributeTables"));
}

TArray<FCharacterAttributeTable*>* AP_RouLikePlayerState::GetCharacterAttributeTables()
{
	return GetTables(CharacterAttributePtr,CharacterAttribute,TEXT("AttributeTables"));
}

FSlotTable* AP_RouLikePlayerState::GetSlotTable(int32 InID)
{
	return GetTable(InID,SlotTablePtr,SlotTables,TEXT("SlotTable"));
}

TArray<FSlotTable*>* AP_RouLikePlayerState::GetSlotTables()
{
	return GetTables(SlotTablePtr,SlotTables,TEXT("SlotTable"));
}

FSlotAttributeTable* AP_RouLikePlayerState::GetAttributeTable(int32 InID)
{
	return GetTable(InID,SlotAttributePtr,SlotAttributeTables,TEXT("AttributeTable"));
}

TArray<FSlotAttributeTable*>* AP_RouLikePlayerState::GetAttributeTables()
{
	return GetTables(SlotAttributePtr,SlotAttributeTables,TEXT("AttributeTable"));
}
