// Fill out your copyright notice in the Description page of Project Settings.

#include "Intro2Player.h"

// Sets default values
AIntro2Player::AIntro2Player()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AIntro2Player::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AIntro2Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AIntro2Player::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AIntro2Player::Move(FVector2D Direction)
{
	AddActorWorldOffset(FVector(Direction, 0.0f) * MoveSpeed);
}