#include "RoulikePropBase.h"

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
