#include "RoulikePropBase.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"
#include "P_RouLike/GamePlay/Game/GameWorld/P_RouLikeHUD.h"

ARoulikePropBase::ARoulikePropBase()
{
	SceneRoot=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneRoot"));
	SceneRoot->SetupAttachment(RootComponent);
	
	WenponMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WenponMeshComponent"));
	WenponMeshComponent->SetupAttachment(SceneRoot);

}

UStaticMeshComponent* ARoulikePropBase::ReWenponMesh()
{
	return WenponMeshComponent;
}



void ARoulikePropBase::BeginPlay()
{
	Super::BeginPlay();
}
