// Copyright Epic Games, Inc. All Rights Reserved.

#include "RouLikeCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "P_RouLike/GamePlay/Game/GameWorld/P_RouLikePlayerState.h"


ARouLikeCharacter::ARouLikeCharacter()
{
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
	
}


void ARouLikeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ARouLikeCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARouLikeCharacter::MoveRight);
	PlayerInputComponent->BindAction("MouseLeft",IE_Pressed, this,  &ARouLikeCharacter::MouseLeftPress);
	PlayerInputComponent->BindAction("MouseLeft",IE_Released, this,  &ARouLikeCharacter::MouseLeftReleased);
	PlayerInputComponent->BindAction("PickUp",IE_Pressed, this,  &ARouLikeCharacter::PickUp);
}

void ARouLikeCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void ARouLikeCharacter::SetTargetProp_Implementation(ATriggerActor* InTargetProp)
{
	TriggerActor=InTargetProp;
}


void ARouLikeCharacter::MoveForward(float Value)
{
	// find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	// get forward vector
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Value);
};

void ARouLikeCharacter::MoveRight(float Value)
{
	// find out which way is right
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
	
	// get right vector 
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	// add movement in that direction
	AddMovementInput(Direction, Value);
}



void ARouLikeCharacter::PickUp_Implementation()
{
	if (TriggerActor&&TriggerActor->GetPropID()!=INDEX_NONE)
	{
		if (AP_RouLikePlayerState* InPlayerState =  Cast<AP_RouLikePlayerState>(GetPlayerState()))
		{
			if (FSlotTable* InSlotTable = InPlayerState->GetSlotTable(TriggerActor->GetPropID()))
			{
				bool IsWenpon=false;
				for (auto& Tmp:InSlotTable->SlotType)
				{
					if (Tmp==ESlotPropType::SLOT_HELMET)
					{
						IsWenpon=true;
					}
				}

				FActorSpawnParameters ActorSpawnParameters;
				ActorSpawnParameters.Instigator = this;
				if (InSlotTable->PropClass&&IsWenpon)
				{
					WenponActor = GetWorld()->SpawnActor<ARoulikeWenpon>(InSlotTable->PropClass,ActorSpawnParameters);
					WenponActor->SetOwner(this);
					if (WenponActor)
					{
						WenponActor->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("LhandSocket"));
						WenponActor->AttachWeapons(GetMesh());
						WenponActor->RegisterSkillToFightComponent();
						
						InPlayerState->AddSlotToInventory(InSlotTable->ID);

						TriggerActor->Destroy();
					}
				}
			}
		}
	}
};

void ARouLikeCharacter::AddProp()
{
}

void ARouLikeCharacter::AddWenpon()
{
}

void ARouLikeCharacter::ChangeWenpon()
{
}

void ARouLikeCharacter::MouseLeftPress_Implementation()
{
	GetFightComponent()->Press();
}

void ARouLikeCharacter::MouseLeftReleased_Implementation()
{
	GetFightComponent()->Released();
}

