#include "Intro2GameMode.h"
#include "Projectile2.h"
#include "Kismet/GameplayStatics.h"

void AIntro2GameMode::BeginPlay()
{
  GetWorld()->GetTimerManager().SetTimer(Timer, this, &AIntro2GameMode::SpawnProjectile, 3.0f, true);
}

void AIntro2GameMode::SpawnProjectile()
{
  FActorSpawnParameters SpawnParams;
  AProjectile2 *Projectile = GetWorld()->SpawnActor<AProjectile2>(ProjectileClass, FVector(0.0f), FRotator::ZeroRotator, SpawnParams);
  APawn *Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

  Projectile->Direction =
      Player->GetActorLocation() - Projectile->GetActorLocation();
  Projectile->Direction.Normalize();
}