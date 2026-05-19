#include "GrapplingMovementComponent.h"

void UGrapplingMovementComponent::PhysCustom(float DeltaTime, int32 Iterations)
{
  Super::PhysCustom(DeltaTime, Iterations);

  switch (CustomMovementMode)
  {
  case CMOVE_Grappling:
    // TODO: implement grapple pull physics here
    break;
  default:
    break;
  }
}
