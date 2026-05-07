// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "Intro2Controller.generated.h"

/**
 *
 */
UCLASS()
class TEACHING_API AIntro2Controller : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext *IMC;

private:
	virtual void BeginPlay() override;
};
