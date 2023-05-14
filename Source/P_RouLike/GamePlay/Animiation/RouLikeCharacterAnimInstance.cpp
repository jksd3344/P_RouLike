#include "RouLikeCharacterAnimInstance.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"

ARouLikeCharacter* URouLikeCharacterAnimInstance::GetRouLikeCharacter()
{
	if (ARouLikeCharacter* InCharacter = Cast<ARouLikeCharacter>(TryGetPawnOwner()))
	{
		return InCharacter;
	}
	return NULL;
}

void URouLikeCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void URouLikeCharacterAnimInstance::NativeBeginPlay()
{
	TrajectoryGenerator = GetRouLikeCharacter()->GetTrajectoryGeneratorComponent();
	DistanceMatching = GetRouLikeCharacter()->GetDistanceMatching();
	Trajectory = TrajectoryGenerator->Trajectory;
	Trajectory.Initialize(5);
}
