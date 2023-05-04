#include "RouLikeType.h"

FRouLikeAttributeData::FRouLikeAttributeData()
	:BaseValue(0.f),CurrentValue(0.f)
{
	
			
}


FRouLikeSlotData::FRouLikeSlotData()
	: SlotID(0), SlotICO(nullptr), PropType(ESlotPropType::SLOT_ALL), CD(0), Number(0)
{
}

void FRouLikeSlotData::Reset()
{
	SlotID=INDEX_NONE;
	SlotICO=nullptr;
	CD=0.f;
	Number=INDEX_NONE;
}
