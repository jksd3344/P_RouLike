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
	/*这个id决定目标的受击动画*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General configuration")
	int32 HitID;
	
	//将box绑定在角色身上开火点上
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AnimAttack")
	FName InSocketName;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AnimAttack")
	TSubclassOf<AHitCollisionBase> HitObjectClass;

	//存在的生命周期
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AnimAttack")
	float LiftTime;

	/*碰撞体大小*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="HitBox",meta=(EditCondition="bHitBox"))
	FVector BoxExtent;

	//如果为false 代表只能服务器生成 如果为true 服务器客户端都可以生成 ,可以在客户端查看效果
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General configuration")
	bool bCanCreateOnClient;
public:
	UPROPERTY()
	bool bHitBox;
};