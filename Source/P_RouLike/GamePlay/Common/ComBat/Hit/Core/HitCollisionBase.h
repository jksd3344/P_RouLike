// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitCollisionBase.generated.h"

UCLASS(BlueprintType,Blueprintable)
class P_ROULIKE_API AHitCollisionBase:public AActor
{
	GENERATED_BODY()
public:
	AHitCollisionBase(const FObjectInitializer& ObjectInitializer);

	/*撞击费血的函数*/
	UFUNCTION()
	virtual void HandleDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/*HitID的设置获取函数*/
	void SetHitID(int32 InNewHit){HitID = InNewHit;}
	const int32 GetHitID()const{return HitID;}

	/*获取子类返回的碰撞盒子*/
	virtual UPrimitiveComponent* GetHitDamage(){return NULL;};

	void SetHitDamageRelativePosition(const FVector &InNewPostion);
protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HitCollision", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* HitCollisionRootComponent;

	/*根据HitID来决定被攻击的动画蒙太奇中的id*/
	UPROPERTY()
	int32 HitID;
};

