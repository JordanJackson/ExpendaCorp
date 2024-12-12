// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ECCharacter.h"
#include "ECPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class EXPENDACORP_API AECPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AECPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACharacter* FPSCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APawn* OverviewPawn;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	void ToggleOverviewPawn();

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> PlayerContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> ToggleOverviewAction;

	bool bIsControllingOverviewPawn = true;
};
