#include "SlotAttributeTable.h"


FSlotAttributeValue::FSlotAttributeValue()
	: GainType(), ValueType(), Value(0)
{
}

FSlotAttributeTable::FSlotAttributeTable()
	:AttributeType(ESlotPropType::SLOT_ALL)
{
}
