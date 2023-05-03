#include "RouLikeGameMethod.h"

#include "EngineUtils.h"

namespace RouLikeGameMethod
{
	

	ARouLikeCharacterBase* FindTarget(const TArray<ECharacterType>& InIgnoreType,ARouLikeCharacterBase* InMyPawn, float InRange)
	{
		auto IsExistIgnoreType = [&](ARouLikeCharacterBase* InNewTarget)->bool
		{
			for (auto &Tmp : InIgnoreType)
			{
				if (InNewTarget->GetCharacterType() == Tmp)
				{
					return true;
				}
			}

			return false;
		};
		
		ARouLikeCharacterBase*Target = NULL;

		if (InMyPawn && !InMyPawn->IsDie()&&InMyPawn->GetWorld())
		{
			float TmpDistance = InRange;
			for (TActorIterator<ARouLikeCharacterBase> It(InMyPawn->GetWorld(),ARouLikeCharacterBase::StaticClass());It;++It)
			{
				if (ARouLikeCharacterBase* NewTarget = *It)
				{
					if (!NewTarget->IsDie()&&NewTarget!=InMyPawn&& !IsExistIgnoreType(NewTarget))
					{
						float Distanct = FVector::Dist(InMyPawn->GetActorLocation(),NewTarget->GetActorLocation());
						/*这里寻找离我最近的角色*/
						if (Distanct<=InRange)
						{
							if (Distanct<=TmpDistance)
							{
								TmpDistance=Distanct;
								Target=NewTarget;
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
