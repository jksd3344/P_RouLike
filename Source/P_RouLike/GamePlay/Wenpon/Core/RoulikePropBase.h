// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/GameStateBase.h"
#include "RoulikePropBase.generated.h"

/**
 * 
 */
UCLASS()
class P_ROULIKE_API ARoulikePropBase : public AActor
{
	GENERATED_BODY()
public:
	ARoulikePropBase();

	UStaticMeshComponent* ReWenponMesh();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	USceneComponent* SceneRoot;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	UStaticMeshComponent* WenponMeshComponent;
};