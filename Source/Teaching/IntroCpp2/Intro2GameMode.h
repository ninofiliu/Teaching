#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Projectile2.h"
#include "Intro2GameMode.generated.h"

/**
 *
 */
UCLASS()
class TEACHING_API AIntro2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AProjectile2> ProjectileClass;

	FTimerHandle Timer;

	virtual void BeginPlay() override;

	void SpawnProjectile();
};
