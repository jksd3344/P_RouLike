// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "TriggerActor.generated.h"

/**
 * 
 */
UCLASS()
class P_ROULIKE_API ATriggerActor : public AActor
{
	GENERATED_BODY()
public:
	ATriggerActor();

	UStaticMeshComponent* ReWenponMesh();

	UFUNCTION()
	virtual void BeginIsCanPickUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void EndIsCanPickUp(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual void BeginPlay() override;

	int32 GetPropID(){return PropID;};

	UFUNCTION(NetMulticast,Reliable)
	void SetPropType(int32 InPropID, UStaticMesh* InMeshComp);

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "RoulikePropBase", meta = (AllowPrivateAccess = "true"))
	USphereComponent* TouchBoxs;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	USceneComponent* SceneRoot;
	
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	UStaticMeshComponent* WenponMeshComponent;

	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int32 PropID;
};