#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "IntroPlayer.generated.h"

UCLASS()
class TEACHING_API AIntroPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AIntroPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
};
