#include "IntroPlayer.h"
#include "Projectile.h"

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
	OnActorBeginOverlap.AddDynamic(this, &AIntroPlayer::OnOverlapBegin);
}

void AIntroPlayer::OnOverlapBegin(AActor *OverlappedActor, AActor *OtherActor)
{
	if (AProjectile *Projectile = Cast<AProjectile>(OtherActor))
	{
		Projectile->Destroy();
	}
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
	UE_LOG(LogTemp, Log, TEXT("x=%f, y=%f"), Value.X, Value.Y);
	AddActorLocalOffset(MoveSpeed * FVector(Value.X, Value.Y, 0.0f));
}
