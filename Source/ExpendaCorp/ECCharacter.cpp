// Fill out your copyright notice in the Description page of Project Settings.


#include "ECCharacter.h"

// Sets default values
AECCharacter::AECCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AECCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AECCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AECCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AECCharacter::Highlight_Implementation()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250);
}

void AECCharacter::ClearHighlight_Implementation()
{
	GetMesh()->SetRenderCustomDepth(false);
}