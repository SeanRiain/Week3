// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerCharacter.h"

// Sets default values
ABasePlayerCharacter::ABasePlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABasePlayerCharacter::OnMove(const FVector2D& Vector)
{
	//FVector2D MovementVector = Value.Get<FVector2D>();

	AddMovementInput(GetActorForwardVector(), Vector.Y);
	AddMovementInput(GetActorRightVector(), Vector.X);

}

void ABasePlayerCharacter::OnLook(const FVector2D& Vector)
{
	//FVector2D LookVector = Value.Get<FVector2D>();

	AddControllerYawInput(Vector.X);
	AddControllerPitchInput(Vector.Y);
}

// Called when the game starts or when spawned
void ABasePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

