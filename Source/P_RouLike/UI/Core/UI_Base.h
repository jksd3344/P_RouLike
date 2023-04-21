// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_Base.generated.h"

UCLASS()
class P_ROULIKE_API UUI_Base : public UUserWidget
{
	GENERATED_BODY()
public:
	template<class T>
	T *GetParents()
	{
		return Cast<T>(ParentWidget);
	}

	void SetParents(UWidget* InWidget) {ParentWidget = InWidget;}
protected:
	UPROPERTY()
	UWidget* ParentWidget;
};