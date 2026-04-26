#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "IntroController.generated.h"

/**
 *
 */
UCLASS()
class TEACHING_API AIntroController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext *IMC;

protected:
	virtual void BeginPlay() override;
};
