#include "IntroGameMode.h"
#include "IntroPlayer.h"
#include "IntroController.h"

AIntroGameMode::AIntroGameMode()
{
  DefaultPawnClass = AIntroPlayer::StaticClass();
  PlayerControllerClass = AIntroController::StaticClass();
}
