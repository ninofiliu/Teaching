#include "IntroPlayer.h"

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

// Called every frame
void AIntroPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Log, TEXT("hello"));
}

// Called to bind functionality to input
void AIntroPlayer::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
