#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GrapplingPlayer.generated.h"

class UGrapplingMovementComponent;

UCLASS()
class TEACHING_API AGrapplingPlayer : public ACharacter
{
  GENERATED_BODY()

public:
  AGrapplingPlayer(const FObjectInitializer &ObjectInitializer);

  // Convenience getter — returns the component cast to our subclass.
  UFUNCTION(BlueprintPure)
  UGrapplingMovementComponent *GetGrapplingMovement() const;

protected:
  virtual void BeginPlay() override;
};
