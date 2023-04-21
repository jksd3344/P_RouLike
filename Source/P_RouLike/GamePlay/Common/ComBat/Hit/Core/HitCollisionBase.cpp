
#include "HitCollisionBase.h"

AHitCollisionBase::AHitCollisionBase(const FObjectInitializer& ObjectInitializer)
{
	InitialLifeSpan = 4.f;
	HitCollisionRootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HitCollisionRootComponent"));
	RootComponent = HitCollisionRootComponent;
}

void AHitCollisionBase::HandleDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}

void AHitCollisionBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AHitCollisionBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (UPrimitiveComponent*InHitComponent = GetHitDamage() )
	{
		InHitComponent->SetHiddenInGame(false);
		InHitComponent->OnComponentBeginOverlap.AddDynamic(this,&AHitCollisionBase::HandleDamage);
	}
}
