#include "RoulikePropBase.h"

#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"
#include "P_RouLike/GamePlay/Game/GameWorld/P_RouLikeHUD.h"

ARoulikePropBase::ARoulikePropBase()
	:PropId(INDEX_NONE)
{
	SceneRoot=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	ProMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProMeshComponent"));
	ProMeshComponent->SetupAttachment(SceneRoot);

	bReplicates=true;
}

UStaticMeshComponent* ARoulikePropBase::ReWenponMesh()
{
	return ProMeshComponent;
}



void ARoulikePropBase::BeginPlay()
{
	Super::BeginPlay();
}
