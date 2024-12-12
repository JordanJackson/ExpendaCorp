// Fill out your copyright notice in the Description page of Project Settings.


#include "ECPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AECPlayerController::AECPlayerController()
{
	bReplicates = true;
}

void AECPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(PlayerContext);

	UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (LocalPlayerSubsystem)
	{
		LocalPlayerSubsystem->AddMappingContext(PlayerContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AECPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedIC = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedIC->BindAction(ToggleOverviewAction, ETriggerEvent::Triggered, this, &ThisClass::ToggleOverviewPawn);
}

void AECPlayerController::ToggleOverviewPawn()
{
	if (bIsControllingOverviewPawn)
	{
		// Possess FPS Pawn
		bIsControllingOverviewPawn = false;
		Possess(FPSCharacter);
	}
	else
	{
		// Possess Overview Pawn
		bIsControllingOverviewPawn = true;
		Possess(OverviewPawn);
	}
}

