#include "Intro2Controller.h"
#include "EnhancedInputSubsystems.h"

void AIntro2Controller::BeginPlay()
{
  Super::BeginPlay();

  UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

  Subsystem->AddMappingContext(IMC, 0);
}