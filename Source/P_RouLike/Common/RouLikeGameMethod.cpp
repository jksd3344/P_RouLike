#include "RouLikeGameMethod.h"

#include "EngineUtils.h"

namespace RouLikeGameMethod
{
	

	ARouLikeCharacterBase* FindTarget(ARouLikeCharacterBase* InThis,float InRange,const TArray<ECharacterType>&InIgnoreType)
	{

		ARouLikeCharacterBase* Target = NULL;
		if (InThis && !InThis->IsDie() && InThis->GetWorld())
		{
			float TmpDistance = InRange;
			for (TActorIterator<ARouLikeCharacterBase> It(InThis->GetWorld(), ARouLikeCharacterBase::StaticClass()); It; ++It)
			{
				if (ARouLikeCharacterBase* NewTarget = *It)
				{
					if (!NewTarget->IsDie() && InThis != NewTarget)
					{
						float Distance = FVector::Dist(InThis->GetActorLocation(), NewTarget->GetActorLocation());
					
						if (Distance <= InRange)
						{
							if (Distance <= TmpDistance)
							{
								TmpDistance = Distance;
								Target = NewTarget;
							}
						}
					}
				}
			}
		}

		return Target;
	}

	ECharacterType GetCharacterType(int32 InCharacterID)
	{
		if (InCharacterID == 1)
		{
			return ECharacterType::CHARACTER_PLAYER_MAIN;
		}
		else if(InCharacterID > 1 && InCharacterID <= 4096)
		{
			return ECharacterType::CHARACTER_PARTNER;
		}
		else if (InCharacterID > 4097 && InCharacterID <= 8119)
		{
			return ECharacterType::CHARACTER_NPC_RESIDENT;
		}
		else if (InCharacterID > 8119 && InCharacterID <= 16423)
		{
			return ECharacterType::CHARACTER_NPC_GUARDIAN;
		}
		else if (InCharacterID > 16423 && InCharacterID <= 30000)
		{
			return ECharacterType::CHARACTER_MONSTER;
		}
		else if (InCharacterID > 30000 && InCharacterID < 100000)
		{
			return ECharacterType::CHARACTER_BOSS;
		}

		return ECharacterType::CHARACTER_NONE;
	}
}
