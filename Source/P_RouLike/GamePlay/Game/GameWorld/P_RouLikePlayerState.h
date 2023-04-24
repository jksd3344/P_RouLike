// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "P_RouLike/Common/RouLikeType.h"
#include "P_RouLike/DataTable/CharacterSkillTbale.h"
#include "P_RouLike/DataTable/SlotAttributeTable.h"
#include "P_RouLike/DataTable/SlotTable.h"
#include "P_RouLikePlayerState.generated.h"


/**
 * 
 */
UCLASS()
class P_ROULIKE_API AP_RouLikePlayerState : public APlayerState
{
	GENERATED_BODY()
public:	
	AP_RouLikePlayerState();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
public:
	UPROPERTY(EditDefaultsOnly,Category="Player Data")
	FName PlayerName;
public:

	/*物品 不支持同步*/	
	UPROPERTY(EditDefaultsOnly,Category="Player Data")
	TMap<int32,FRouLikeSlotData> InventorySlots;

	/*物品装备的增删改查*/
	bool AddSlotToInventory(int32 InSlotID);
	void DeleteSlotToInventory(int32 InSlotID);
	FRouLikeSlotData* GetInventorySlotData(int32 InInventoryID);
	
	void InitializeInventorySlot(TMap<int32,FRouLikeSlotData> InventorySlots);


	/*是否存在可叠加*/
	bool IsExistInInventory(int32 InItemID);



	

	
public:
	/*数据表操作*/
	FCharacterSkillTable* GetCharacterSkillTable(const FName& InSkillKey, int32 InCharacterTableID);
	TArray<FCharacterSkillTable*>* GetCharacterSkillTables();

	FCharacterAttributeTable* GetCharacterAttributeTable(int32 InCharacterTableID);
	TArray<FCharacterAttributeTable*>* GetCharacterAttributeTables();

	FSlotTable* GetSlotTable(int32 InID);
	TArray<FSlotTable*>* GetSlotTables();

	FSlotAttributeTable* GetAttributeTable(int32 InID);
	TArray<FSlotAttributeTable*>* GetAttributeTables();


protected:
	
	template<class T>
	TArray<T*>* GetTables(UDataTable* InTable,TArray<T*>&OutTables,const FString &MsgTag = TEXT("MyTable"))
	{
		if (!OutTables.Num())
		{
			if (InTable)
			{
				InTable->GetAllRows(MsgTag,OutTables);
			}
		}
		return &OutTables;
	}


	template<class T>
	T* GetTable(int32 InTableID,UDataTable* InTable,TArray<T*> &OutTable,const FString &MsgTag=TEXT("MyTable"))
	{
		if (TArray<T*>* InTables = GetTables<T>(InTable,OutTable,MsgTag))
		{
			if (InTables->Num())
			{
				if (auto InTableTmp = InTables->FindByPredicate([&](T* MyTable){return MyTable->ID==InTableID;}))
				{
					return *(InTableTmp);
				}
			}
		}
		return NULL;
	}

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UDataTable* CharacterSkillTablePtr;
	TArray<FCharacterSkillTable*> CharacterSkillTables;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UDataTable* CharacterAttributePtr;
	TArray<FCharacterAttributeTable*> CharacterAttribute;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UDataTable* SlotTablePtr;
	TArray<FSlotTable*> SlotTables;

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UDataTable* SlotAttributePtr;
	TArray<FSlotAttributeTable*> SlotAttributeTables;
};

