#include "GrapplingPlayer.h"
#include "GrapplingMovementComponent.h"

// Pass our custom movement component class to ACharacter via ObjectInitializer.
// This replaces the default UCharacterMovementComponent before the base constructor runs.
AGrapplingPlayer::AGrapplingPlayer(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<UGrapplingMovementComponent>(
          ACharacter::CharacterMovementComponentName))
{
}

void AGrapplingPlayer::BeginPlay()
{
  Super::BeginPlay();

  UCharacterMovementComponent *Movement = GetCharacterMovement();

  UE_LOG(LogTemp, Log, TEXT("Movement mode: %s"), *UEnum::GetValueAsString(Movement->MovementMode));

  Movement->SetMovementMode(MOVE_Custom, CMOVE_Grappling);

  UE_LOG(LogTemp, Log, TEXT("Movement mode: %s"), *UEnum::GetValueAsString(Movement->MovementMode));
}

UGrapplingMovementComponent *AGrapplingPlayer::GetGrapplingMovement() const
{
  return Cast<UGrapplingMovementComponent>(GetCharacterMovement());
}
