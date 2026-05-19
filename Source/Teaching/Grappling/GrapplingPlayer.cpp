#include "GrapplingPlayer.h"
#include "GrapplingMovementComponent.h"
#include "Camera/CameraComponent.h"

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
}

void AGrapplingPlayer::ThrowHook()
{
  UCameraComponent *Camera = FindComponentByClass<UCameraComponent>();
  if (!Camera)
    return;

  const FVector Start = Camera->GetComponentLocation();
  const FVector End = Start + Camera->GetForwardVector() * 1000.f; // 10 m

  FHitResult Hit;
  FCollisionQueryParams Params;
  Params.AddIgnoredActor(this);

  const bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params);
  if (!bHit)
    return;

  UGrapplingMovementComponent *GrapplingMovement = GetGrapplingMovement();
  GrapplingMovement->GrappleTarget = Hit.ImpactPoint;
  GrapplingMovement->SetMovementMode(MOVE_Custom, CMOVE_Grappling);

  UE_LOG(LogTemp, Log, TEXT("Hook attached to: %s"), *Hit.ImpactPoint.ToString());
}

UGrapplingMovementComponent *AGrapplingPlayer::GetGrapplingMovement() const
{
  return Cast<UGrapplingMovementComponent>(GetCharacterMovement());
}
