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

	UFUNCTION()
	virtual void BeginIsCanPickUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndIsCanPickUp(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void BeginPlay() override;

	int32 GetPropID(){return PropID;};

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RoulikePropBase", meta = (AllowPrivateAccess = "true"))
	USphereComponent* TouchBoxs;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	USceneComponent* SceneRoot;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	UStaticMeshComponent* WenponMeshComponent;

	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	int32 PropID;
};