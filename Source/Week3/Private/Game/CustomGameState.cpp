// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CustomGameState.h"

#include "GameFramework/PlayerState.h"

void ACustomGameState::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("[GameState::BeginPlay] GS is ready (exists on server & clients)."));
}

void ACustomGameState::AddPlayerState(APlayerState* PlayerState)
{
	Super::AddPlayerState(PlayerState);

	UE_LOG(LogTemp, Warning, TEXT("[GameState::AddPlayerState] PlayerState Added %s"), *PlayerState->GetPlayerName());
}
