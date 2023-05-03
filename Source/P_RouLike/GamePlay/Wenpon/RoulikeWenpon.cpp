#include "RoulikeWenpon.h"
#include "P_RouLike/GamePlay/Game/Character/RouLikeCharacter.h"
#include "P_RouLike/GamePlay/Game/SkillGAS/RouLikeWenponAttributeSet.h"

ARoulikeWenpon::ARoulikeWenpon()
{
	WenponAbilitySystemComponent = CreateDefaultSubobject<URouLikeAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	WenponAbilitySystemComponent->SetIsReplicated(true);
	
	WenponAttributeSet = CreateDefaultSubobject<URouLikeWenponAttributeSet>(TEXT("AttributeSet"));
}

void ARoulikeWenpon::AttachWeapons(USkeletalMeshComponent* StaticMeshComp, const FName Socket)
{
	AttachToComponent(StaticMeshComp,FAttachmentTransformRules::KeepRelativeTransform,Socket);
}

void ARoulikeWenpon::RegisterSkillToFightComponent(const int32 WenponID,const FName& InKey)
{
	if (ARouLikeCharacter* InCharacter = Cast<ARouLikeCharacter>(GetOwner()))
	{
		InCharacter->GetFightComponent()->RepickRegisterComboAttack(WenponID,InKey);
	}
}
