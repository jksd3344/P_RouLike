#include "PlayerDataComponent.h"

#include "Net/UnrealNetwork.h"

UPlayerDataComponent::UPlayerDataComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UPlayerDataComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UPlayerDataComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

}
