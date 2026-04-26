#include "IntroPlayer.h"
#include "Projectile.h"
#include "IntroGameMode.h"

// Sets default values
AIntroPlayer::AIntroPlayer()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AIntroPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AIntroPlayer::OnOverlapBegin(AActor *OtherActor)
{
	UE_LOG(LogTemp, Log, TEXT("overlap"));
	if (AProjectile *Projectile = Cast<AProjectile>(OtherActor))
	{
		Projectile->Destroy();
		Lives--;
		if (Lives <= 0)
		{
			if (AIntroGameMode *GameMode = Cast<AIntroGameMode>(GetWorld()->GetAuthGameMode()))
			{
				GameMode->StopSpawning();
			}
			UE_LOG(LogTemp, Log, TEXT("game over"));
			MoveSpeed = 0;
		}
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("cast failed"));
	}
}

void AIntroPlayer::NotifyActorBeginOverlap(AActor *OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	OnOverlapBegin(OtherActor);
}

// Called every frame
void AIntroPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AIntroPlayer::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AIntroPlayer::Move(FVector2D Value)
{
	AddActorLocalOffset(MoveSpeed * FVector(Value.X, Value.Y, 0.0f));
}
