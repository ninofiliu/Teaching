#include "GrapplingMovementComponent.h"

void UGrapplingMovementComponent::PhysCustom(float DeltaTime, int32 Iterations)
{
  Super::PhysCustom(DeltaTime, Iterations);

  switch (CustomMovementMode)
  {
  case CMOVE_Grappling:
    PhysGrappling(DeltaTime, Iterations);
    break;
  default:
    break;
  }
}

void UGrapplingMovementComponent::PhysGrappling(float DeltaTime, int32 Iterations)
{
  if (DeltaTime < MIN_TICK_TIME)
    return;

  const FVector GrappleTarget = FVector::ZeroVector;
  const FVector ToTarget = GrappleTarget - UpdatedComponent->GetComponentLocation();
  const float Distance = ToTarget.Size();

  if (Distance > KINDA_SMALL_NUMBER)
  {
    // Accelerate toward the target each tick.
    const FVector PullDirection = ToTarget / Distance;
    Velocity += PullDirection * GrapplePullForce * DeltaTime;
  }

  // Move the capsule, resolving collisions along the way.
  Iterations++;
  bJustTeleported = false;

  FHitResult Hit(1.f);
  SafeMoveUpdatedComponent(Velocity * DeltaTime, UpdatedComponent->GetComponentQuat(), true, Hit);

  if (Hit.IsValidBlockingHit())
  {
    HandleImpact(Hit, DeltaTime, Velocity * DeltaTime);
    SlideAlongSurface(Velocity * DeltaTime, 1.f - Hit.Time, Hit.Normal, Hit, true);
  }
}
