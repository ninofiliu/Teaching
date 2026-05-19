#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GrapplingMovementComponent.generated.h"

// Custom movement mode sub-values used with MOVE_Custom.
// Add new grappling sub-modes here as the mechanic grows.
UENUM(BlueprintType)
enum ECustomMovementMode : uint8
{
  CMOVE_Grappling UMETA(DisplayName = "Grappling"),
};

UCLASS()
class TEACHING_API UGrapplingMovementComponent : public UCharacterMovementComponent
{
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grappling")
  float GrappleDamping = 0.5f;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grappling")
  float GrapplePullForce = 10.f;

  // World-space position the character is being pulled toward.
  FVector GrappleTarget = FVector::ZeroVector;

protected:
  // Called by the engine when MovementMode == MOVE_Custom.
  // CustomMovementMode holds the ECustomMovementMode sub-value.
  virtual void PhysCustom(float DeltaTime, int32 Iterations) override;

private:
  void PhysGrappling(float DeltaTime, int32 Iterations);
};
