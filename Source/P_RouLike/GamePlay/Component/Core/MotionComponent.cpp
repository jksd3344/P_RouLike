#include "MotionComponent.h"
#include "P_RouLike/GamePlay/Game/Character/Core/RouLikeCharacterBase.h"

UMotionComponent::UMotionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMotionComponent::BeginPlay()
{
	Super::BeginPlay();
	RouLikeCharacterBase = Cast<ARouLikeCharacterBase>(GetOwner());
}
