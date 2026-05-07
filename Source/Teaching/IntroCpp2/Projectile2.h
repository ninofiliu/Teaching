// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile2.generated.h"

UCLASS()
class TEACHING_API AProjectile2 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile2();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Speed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector Direction;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
