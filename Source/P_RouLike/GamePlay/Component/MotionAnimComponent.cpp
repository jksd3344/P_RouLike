// Fill out your copyright notice in the Description page of Project Settings.
#include "MotionAnimComponent.h"

#include "MotionMatchingUtil/MMBlueprintFunctionLibrary.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"


// Sets default values for this component's properties
UMotionAnimComponent::UMotionAnimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

ARouLikeCharacter* UMotionAnimComponent::GetRouLikeCharacter()
{
	if (ARouLikeCharacter* InCharacter = Cast<ARouLikeCharacter>(GetOwner()))
	{
		return InCharacter;
	}
	return NULL;
}

void UMotionAnimComponent::MotionMove(const float X, const float Y)
{
	if (!GetRouLikeCharacter()->HasAuthority())
	{
		Server_MotionMove(X,Y);
	}
}

void UMotionAnimComponent::Server_MotionMove_Implementation(const float X, const float Y)
{
	Multicast_MotionMove(X,Y,GetRouLikeCharacter()->GetActorLocation(),GetWorld()->GetDeltaSeconds());
}

void UMotionAnimComponent::Multicast_MotionMove_Implementation(const float X, const float Y, const FVector Location,float Delta)
{
	if (!GetRouLikeCharacter()->HasAuthority())
	{
		GetRouLikeCharacter()->SetActorLocation(Location);
	}
	UMMBlueprintFunctionLibrary::GetVectorRelativeToCamera(X,Y,GetRouLikeCharacter()->TopDownCameraComponent);
	GetRouLikeCharacter()->GetTrajectoryGeneratorComponent()->SetTrajectoryInput(X,Y,0);
	GetRouLikeCharacter()->GetTrajectoryErrorWarpingComponent()->ApplyTrajectoryErrorWarping(Delta,1.0f);
}


// Called when the game starts
void UMotionAnimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GetRouLikeCharacter()->GetTrajectoryGeneratorComponent()->SetInputProfile(InputProfile);
	GetRouLikeCharacter()->GetMesh()->GetAnimInstance()->SetRootMotionMode(ERootMotionMode::RootMotionFromEverything);
}


// Called every frame
void UMotionAnimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	MotionMove(M_X,M_Y);
}

