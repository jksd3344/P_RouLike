#include "CombatType.h"

#include "CombatInterface/CombatInterface.h"

FRouLikeCombat::FRouLikeCombat()
	: CombatIndex(INDEX_NONE),
	  bLongPress(false),
	  bShortPress(false),
	  MaxIndex(0),
	  Character(nullptr)
{
	
}

void FRouLikeCombat::UpdateCombatIndex()
{
	check(MaxIndex>0)

	CombatIndex++;
	if (CombatIndex > MaxIndex)
	{
		CombatIndex = 1;
	}
}

void FRouLikeCombat::Press()
{
	//只负责第一次的执行,剩下的由animnotifystate执行
	if (CombatIndex==INDEX_NONE)
	{
		CombatIndex++;
		Character->ComboAttack(ComboKey);
	}

	bShortPress = true;
	bLongPress = true;
}

void FRouLikeCombat::Released()
{
	bLongPress = false;
}

void FRouLikeCombat::Reset()
{
	CombatIndex=INDEX_NONE;
}
