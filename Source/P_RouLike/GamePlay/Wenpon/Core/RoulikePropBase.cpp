#include "RoulikePropBase.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"
#include "P_RouLike/GamePlay/Game/GameWorld/P_RouLikeHUD.h"

ARoulikePropBase::ARoulikePropBase()
{
	SceneRoot=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneRoot"));
	SceneRoot->SetupAttachment(RootComponent);
	
	WenponMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WenponMeshComponent"));
	WenponMeshComponent->SetupAttachment(SceneRoot);

	TouchBoxs=CreateDefaultSubobject<USphereComponent>(TEXT("TouchBoxs"));
	TouchBoxs->SetupAttachment(SceneRoot);
	TouchBoxs->OnComponentBeginOverlap.AddDynamic(this,&ARoulikePropBase::BeginIsCanPickUp);
	TouchBoxs->OnComponentEndOverlap.AddDynamic(this,&ARoulikePropBase::EndIsCanPickUp);
}

UStaticMeshComponent* ARoulikePropBase::ReWenponMesh()
{
	return WenponMeshComponent;
}

void ARoulikePropBase::BeginIsCanPickUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ARouLikeCharacter* InTargetActor = Cast<ARouLikeCharacter>(OtherActor))
	{
		if (!InTargetActor->IsDie())
		{
			if (AP_RouLikeHUD* RouLikeHUD =  Cast<AP_RouLikeHUD>(GetWorld()->GetFirstPlayerController()->GetHUD()))
			{
				InTargetActor->SetTargetPropID(PropID);
				RouLikeHUD->GetMainScreen()->SetPickButtonVisiable(false);
			}
		}
	}
}

void ARoulikePropBase::EndIsCanPickUp(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ARouLikeCharacter* InTargetActor = Cast<ARouLikeCharacter>(OtherActor))
	{
		if (!InTargetActor->IsDie())
		{
			if (AP_RouLikeHUD* RouLikeHUD =  Cast<AP_RouLikeHUD>(GetWorld()->GetFirstPlayerController()->GetHUD()))
			{
				InTargetActor->SetTargetPropID(INDEX_NONE);
				RouLikeHUD->GetMainScreen()->SetPickButtonVisiable(true);
			}
		}
	}
}



void ARoulikePropBase::BeginPlay()
{
	Super::BeginPlay();
}
