// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CustomGameMode.h"

#include "Game/CustomGameSession.h"
#include "Game/CustomGameState.h"
#include "Player/CustomPlayerController.h"
#include "Player/CustomPlayerPawn.h"
#include "Player/CustomPlayerState.h"

ACustomGameMode::ACustomGameMode()
{
	DefaultPawnClass = ACustomPlayerPawn::StaticClass();
	PlayerControllerClass = ACustomPlayerController::StaticClass();
	PlayerStateClass = ACustomPlayerState::StaticClass();
	GameStateClass = ACustomGameState::StaticClass();

	UE_LOG(LogTemp, Warning, TEXT("[GameMode::Ctor] GM constructed (server-only)."));
}

void ACustomGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UE_LOG(LogTemp, Warning, TEXT("[GameMode::InitGame] Map=%s, Options=%s"), *MapName, *Options);
}

void ACustomGameMode::InitGameState()
{
	Super::InitGameState();

	UE_LOG(LogTemp, Warning, TEXT("[GameMode::InitGameState]"));
}

void ACustomGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	UE_LOG(LogTemp, Warning, TEXT("[GameMode::PostLogin] New player controller joined: %s"),
		*GetNameSafe(NewPlayer));
}

void ACustomGameMode::StartPlay()
{
	Super::StartPlay();

	UE_LOG(LogTemp, Warning, TEXT("[GameMode::StartPlay] Match flow entering Play on server."));
	
	if(ACustomGameState* gs = GetGameState<ACustomGameState>())
	{
		UE_LOG(LogTemp, Warning, TEXT("  - GameState: %s"), *gs->GetClass()->GetName());
		
		for(APlayerState* ps : gs->PlayerArray)
		{
			UE_LOG(LogTemp, Warning, TEXT("  - PlayerState: %s (PlayerName=%s)"), *ps->GetClass()->GetName(), *ps->GetPlayerName());
		}
	}
}