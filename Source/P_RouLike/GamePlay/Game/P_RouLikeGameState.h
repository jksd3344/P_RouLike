// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "P_RouLike/DataTable/CharacterAttributeTable.h"
#include "P_RouLike/DataTable/CharacterSkillTbale.h"
#include "P_RouLikeGameState.generated.h"

/**
 * 
 */
UCLASS()
class P_ROULIKE_API AP_RouLikeGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	FCharacterSkillTable* GetCharacterSkillTable(const FName& InSkillKey, int32 InCharacterTableID);
	TArray<FCharacterSkillTable*>* GetCharacterSkillTables();

	FCharacterAttributeTable* GetCharacterAttributeTable(int32 InCharacterTableID);
	TArray<FCharacterAttributeTable*>* GetCharacterAttributeTables();
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
				if (auto InTable = InTables->FindByPredicate([&](T* MyTable){return MyTable->ID==InTableID;}))
				{
					return *(InTable);
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
};

