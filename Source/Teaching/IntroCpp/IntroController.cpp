#include "IntroController.h"
#include "EnhancedInputSubsystems.h"

void AIntroController::BeginPlay()
{
  Super::BeginPlay();

  UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

  Subsystem->ClearAllMappings();
  Subsystem->AddMappingContext(IMC, 0);
}