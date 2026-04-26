#include "IntroGameMode.h"
#include "Projectile.h"
#include "IntroPlayer.h"
#include "Kismet/GameplayStatics.h"

AIntroGameMode::AIntroGameMode()
{
}

void AIntroGameMode::BeginPlay()
{
  Super::BeginPlay();

  GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AIntroGameMode::SpawnProjectile, 1.0f, true);
}

void AIntroGameMode::SpawnProjectile()
{
  if (!ProjectileClass)
    return;

  APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
  if (!PlayerPawn)
    return;

  const float HalfSize = 500.0f;
  FVector SpawnLocation(
      FMath::RandRange(-HalfSize, HalfSize),
      FMath::RandRange(-HalfSize, HalfSize),
      0.0f);

  FActorSpawnParameters SpawnParams;
  AProjectile *Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
  if (Projectile)
  {
    FVector Direction = (PlayerPawn->GetActorLocation() - SpawnLocation).GetSafeNormal() * ProjectileSpeed;
    Projectile->Direction = Direction;
  }
}

void AIntroGameMode::StopSpawning()
{
  GetWorldTimerManager().ClearTimer(SpawnTimerHandle);
}