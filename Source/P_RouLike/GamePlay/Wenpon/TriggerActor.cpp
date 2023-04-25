#include "TriggerActor.h"

#include "Components/StaticMeshComponent.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"
#include "P_RouLike/GamePlay/Game/GameWorld/P_RouLikeHUD.h"

ATriggerActor::ATriggerActor()
{
	SceneRoot=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneRoot"));
	SceneRoot->SetupAttachment(RootComponent);
	
	WenponMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WenponMeshComponent"));
	WenponMeshComponent->SetupAttachment(SceneRoot);

	TouchBoxs=CreateDefaultSubobject<USphereComponent>(TEXT("TouchBoxs"));
	TouchBoxs->SetupAttachment(SceneRoot);
	TouchBoxs->OnComponentBeginOverlap.AddDynamic(this,&ATriggerActor::BeginIsCanPickUp);
	TouchBoxs->OnComponentEndOverlap.AddDynamic(this,&ATriggerActor::EndIsCanPickUp);
}

UStaticMeshComponent* ATriggerActor::ReWenponMesh()
{
	return WenponMeshComponent;
}

void ATriggerActor::BeginIsCanPickUp(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ARouLikeCharacter* InTargetActor = Cast<ARouLikeCharacter>(OtherActor))
	{
		if (!InTargetActor->IsDie())
		{
			if (AP_RouLikeHUD* RouLikeHUD =  Cast<AP_RouLikeHUD>(GetWorld()->GetFirstPlayerController()->GetHUD()))
			{
				InTargetActor->SetTargetProp(this);
				RouLikeHUD->GetMainScreen()->SetPickButtonVisiable(false);
			}
		}
	}
}

void ATriggerActor::EndIsCanPickUp(UPrimitiveComponent* OverlapedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ARouLikeCharacter* InTargetActor = Cast<ARouLikeCharacter>(OtherActor))
	{
		if (!InTargetActor->IsDie())
		{
			if (AP_RouLikeHUD* RouLikeHUD =  Cast<AP_RouLikeHUD>(GetWorld()->GetFirstPlayerController()->GetHUD()))
			{
				InTargetActor->SetTargetProp(nullptr);
				RouLikeHUD->GetMainScreen()->SetPickButtonVisiable(true);
			}
		}
	}
}



void ATriggerActor::BeginPlay()
{
	Super::BeginPlay();
}
