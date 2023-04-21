// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "P_RouLike/GamePlay/Common/ComBat/Hit/Core/HitCollisionBase.h"
#include "AnimNotify_Attack.generated.h"

/**
 * 
 */
UCLASS(meta=(DisplayName="Attack"))
class P_ROULIKE_API UAnimNotify_Attack : public UAnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_Attack();
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
	virtual FString GetNotifyName_Implementation() const override;


#if WITH_EDITORONLY_DATA
	virtual FLinearColor GetEditorColor() override;
#endif 
	
protected:
	/*���id����Ŀ����ܻ�����*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General configuration")
	int32 HitID;
	
	//��box���ڽ�ɫ���Ͽ������
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AnimAttack")
	FName InSocketName;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AnimAttack")
	TSubclassOf<AHitCollisionBase> HitObjectClass;

	//���ڵ���������
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AnimAttack")
	float LiftTime;

	/*��ײ���С*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HitBox",meta=(EditCondition="bHitBox"))
	FVector BoxExtent;

	//���Ϊfalse ����ֻ�ܷ��������� ���Ϊtrue �������ͻ��˶��������� ,�����ڿͻ��˲鿴Ч��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General configuration")
	bool bCanCreateOnClient;
public:
	UPROPERTY()
	bool bHitBox;
};