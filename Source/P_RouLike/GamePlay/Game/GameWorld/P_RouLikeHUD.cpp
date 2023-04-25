#include "P_RouLikeHUD.h"

#include "Blueprint/UserWidget.h"
#include "P_RouLike/UI/Game/UI_MainScreen.h"

AP_RouLikeHUD::AP_RouLikeHUD()
{
}

void AP_RouLikeHUD::BeginPlay()
{
	Super::BeginPlay();

	if (MainScreenClass)
	{
		MainScreen = CreateWidget<UUI_MainScreen>(GetWorld(),MainScreenClass);
		MainScreen->AddToViewport(2);
	};
}

UUI_MainScreen* AP_RouLikeHUD::GetMainScreen()
{
	return MainScreen;
};
