#include "UI_CharacterBarWidget.h"

#include "Components/ProgressBar.h"



void UUI_CharacterBarWidget::SetHealth(float InPercentage)
{
	HealthBar->SetPercent(InPercentage);
}

void UUI_CharacterBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
}


