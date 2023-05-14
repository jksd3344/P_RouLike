// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/InputProfile.h"
#include "Data/MotionTraitField.h"

#include "MotionAnimComponent.generated.h"

class ARouLikeCharacter;

UCLASS(Blueprintable)
class P_ROULIKE_API UMotionAnimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMotionAnimComponent();

	UFUNCTION(BlueprintCallable,BlueprintPure)
	ARouLikeCharacter* GetRouLikeCharacter();

	UFUNCTION(BlueprintCallable)
	void MotionMove(const float X,const float Y);
	
	UFUNCTION(Server,Reliable)
	void Server_MotionMove(const float X,const float Y);

	UFUNCTION(NetMulticast,Reliable)
	void Multicast_MotionMove(const float X,const float Y,const FVector Location,float Delta);

	UPROPERTY(BlueprintReadWrite)
	FInputProfile InputProfile ;

	UPROPERTY(BlueprintReadWrite)
	FMotionTraitField MotionTraitField;

	UPROPERTY(BlueprintReadWrite)
	bool IsSprint; 
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
