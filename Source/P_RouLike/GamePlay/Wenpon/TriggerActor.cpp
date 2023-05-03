#include "TriggerActor.h"

#include "Components/StaticMeshComponent.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"
#include "P_RouLike/GamePlay/Game/GameWorld/P_RouLikeHUD.h"
#include "P_RouLike/GamePlay/Game/GameWorld/P_RouLikePlayerController.h"

ATriggerActor::ATriggerActor()
{
	SceneRoot=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneRoot"));
	SceneRoot->SetupAttachment(RootComponent);
	
	WenponMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WenponMeshComponent"));
	WenponMeshComponent->SetupAttachment(SceneRoot);
	WenponMeshComponent->SetCollisionProfileName(TEXT("OverlapAll"));
	
	TouchBoxs=CreateDefaultSubobject<USphereComponent>(TEXT("TouchBoxs"));
	TouchBoxs->SetupAttachment(SceneRoot);
	TouchBoxs->SetHiddenInGame(false);
	TouchBoxs->SetSphereRadius(170);
	TouchBoxs->OnComponentBeginOverlap.AddDynamic(this,&ATriggerActor::BeginIsCanPickUp);
	TouchBoxs->OnComponentEndOverlap.AddDynamic(this,&ATriggerActor::EndIsCanPickUp);
	
	bReplicates =true;
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
			if (GetLocalRole()==ROLE_Authority)
			{
				SetOwner(InTargetActor->GetController());
				InTargetActor->SetTargetProp(this);
			}
			
			if (AP_RouLikePlayerController* PlayerController =  Cast<AP_RouLikePlayerController>(InTargetActor->GetController()))
			{
				PlayerController->PickUpPropClueForWidet(false);
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
			if (GetLocalRole()==ROLE_Authority)
			{
				InTargetActor->SetTargetProp(nullptr);
			}
			if (AP_RouLikePlayerController* PlayerController =  Cast<AP_RouLikePlayerController>(InTargetActor->GetController()))
			{
				PlayerController->PickUpPropClueForWidet(true);
			}
		
		}
	}
}



void ATriggerActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATriggerActor::SetPropType_Implementation(int32 InPropID, UStaticMesh* InMeshComp)
{
	PropID = InPropID;
	WenponMeshComponent->SetStaticMesh(InMeshComp);
}

