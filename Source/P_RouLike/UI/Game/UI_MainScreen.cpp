#include "UI_MainScreen.h"


void UUI_MainScreen::SetPickButtonVisiable(bool IsHid)
{
	if (IsHid)
	{
		PickButton->SetVisibility(ESlateVisibility::Hidden);
	}else
	{
		PickButton->SetVisibility(ESlateVisibility::Visible);
	}
}

void UUI_MainScreen::NativeConstruct()
{
	Super::NativeConstruct();
	if (PickButton)
	{
		PickButton->SetVisibility(ESlateVisibility::Hidden);
	}
}


