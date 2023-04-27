
#include "HitCollisionBox.h"
#include "Components/BoxComponent.h"

AHitCollisionBox::AHitCollisionBox(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	HitDamage = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	HitDamage->SetupAttachment(RootComponent);
}

UPrimitiveComponent* AHitCollisionBox::GetHitDamage()
{
	return HitDamage;
}

void AHitCollisionBox::SetBoxExtent(const FVector& InNewBoxExtent)
{
	HitDamage->SetBoxExtent(InNewBoxExtent);
}

void AHitCollisionBox::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AHitCollisionBox::BeginPlay()
{
	Super::BeginPlay();
}
