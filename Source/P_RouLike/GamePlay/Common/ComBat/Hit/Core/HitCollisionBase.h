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

	/*ײ����Ѫ�ĺ���*/
	UFUNCTION()
	virtual void HandleDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/*HitID�����û�ȡ����*/
	void SetHitID(int32 InNewHit){HitID = InNewHit;}
	const int32 GetHitID()const{return HitID;}

	/*��ȡ���෵�ص���ײ����*/
	virtual UPrimitiveComponent* GetHitDamage(){return NULL;};

	void SetHitDamageRelativePosition(const FVector &InNewPostion);
protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "HitCollision", meta = (AllowPrivateAccess = "true"))
	class USceneComponent* HitCollisionRootComponent;

	/*����HitID�������������Ķ�����̫���е�id*/
	UPROPERTY()
	int32 HitID;
};

