// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnitInterface.h"
#include "ECCharacter.generated.h"

UCLASS()
class EXPENDACORP_API AECCharacter : public ACharacter, public IUnitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AECCharacter();

	// Unit Interface
	virtual void Highlight_Implementation() override;
	virtual void ClearHighlight_Implementation() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
