// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/GamePlay/Common/ComBat/Hit/Core/HitCollisionBase.h"
#include "HitCollisionBox.generated.h"

UCLASS(BlueprintType,Blueprintable)
class P_ROULIKE_API AHitCollisionBox:public AHitCollisionBase
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "BaseAttrubute", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* HitDamage;
public:
	AHitCollisionBox(const FObjectInitializer& ObjectInitializer);

	/*��ȡ���෵�ص���ײ����*/
	virtual UPrimitiveComponent* GetHitDamage();

	//���÷�Χ
	void SetBoxExtent(const FVector& InNewBoxExtent);
protected:
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;


};

