
#pragma once

#include "CoreMinimal.h"
#include "Core/RouLikeCharacterBase.h"
#include "GameFramework/Character.h"
#include "P_RouLike/GamePlay/Wenpon/RoulikeWenpon.h"
#include "P_RouLike/GamePlay/Wenpon/TriggerActor.h"
#include "P_RouLike/GamePlay/Wenpon/Core/RoulikePropBase.h"
#include "RouLikeCharacter.generated.h"

UCLASS(Blueprintable)
class ARouLikeCharacter : public ARouLikeCharacterBase
{
	GENERATED_BODY()

public:
	ARouLikeCharacter();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UFUNCTION(Server, Reliable)
	void SetTargetProp(ATriggerActor* InTargetProp);

	virtual AActor* GetTarget()override;
private:
	UFUNCTION()
	void MoveForward(float Value);
	
	UFUNCTION()
	void MoveRight(float Value);
	
	UFUNCTION(Server, Reliable)
	void MouseLeftPress();
	
	UFUNCTION(Server, Reliable)
	void MouseLeftReleased();

	UFUNCTION(Server,Reliable)
	void PickUp();


private:
	UPROPERTY()
	ATriggerActor* TriggerActor;

	UPROPERTY()
	ARoulikeWenpon* RightHandWenponActor;

	UPROPERTY()
	ARoulikeWenpon* LeftHandWenponActor;
};



