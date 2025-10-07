// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CustomPlayerController.h"

void ACustomPlayerController::BeginPlayingState()
{
	Super::BeginPlayingState();
	
	UE_LOG(LogTemp, Warning, TEXT("[PlayerController::BeginPlayingState] PC entered playing state (owning client + server)."));
}

void ACustomPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	UE_LOG(LogTemp, Warning, TEXT("[PlayerController::OnPossess] PC possessed pawn: %s"), *GetNameSafe(InPawn));
}

void ACustomPlayerController::OnUnPossess()
{
	Super::OnUnPossess();
	
	UE_LOG(LogTemp, Warning, TEXT("[PlayerController::OnUnPossess] PC unpossessed current pawn."));
}
