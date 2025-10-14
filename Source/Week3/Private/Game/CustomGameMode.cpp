// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CustomGameMode.h"

//#include "Game/CustomGameSession.h"
#include "Game/CustomGameState.h"
#include "Player/CustomPlayerController.h"
#include "Player/CustomPlayerPawn.h"
#include "Player/CustomPlayerState.h"
#include "Actors/CollectableSpawnPoint.h"
#include "Actors/Collectable.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
//#include "Engine/Utils.h"
#include <EngineUtils.h>



ACustomGameMode::ACustomGameMode()
{
	DefaultPawnClass = ACustomPlayerPawn::StaticClass();
	PlayerControllerClass = ACustomPlayerController::StaticClass();
	PlayerStateClass = ACustomPlayerState::StaticClass();
	GameStateClass = ACustomGameState::StaticClass();

	ScoreToWin = 5;
	LastSpawnIndex = -1;
	bGameOver = false;

	CollectableClass = ACollectable::StaticClass();

	UE_LOG(LogTemp, Warning, TEXT("[GameMode::Ctor] GM constructed (server-only)."));
}

void ACustomGameMode::BeginPlay()
{
	Super::BeginPlay();

	GatherSpawnPoints();
	SpawnCollectableAtRandomPoint();
}

void ACustomGameMode::GatherSpawnPoints()
{
	if (UWorld* world = GetWorld())
	{
		SpawnPoints.Empty();

		for (ACollectableSpawnPoint* spawnPoint : TActorRange<ACollectableSpawnPoint>(world))
		{
			if (IsValid(spawnPoint))
				SpawnPoints.Add(spawnPoint);
		}
	}
}

void ACustomGameMode::SpawnCollectableAtRandomPoint()
{
	if (bGameOver) return;
	if (!CollectableClass) return;
	if (!GetWorld()) return;
	if (SpawnPoints.Num() == 0) return;

	int32 NewIndex = 0;
	if (SpawnPoints.Num() > 1)
	{
		do
		{
			NewIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);
		} 
		while (NewIndex == LastSpawnIndex);
	}

	ACollectableSpawnPoint* Chosen = SpawnPoints[NewIndex];
	LastSpawnIndex = NewIndex;

	FTransform Xform = Chosen->GetActorTransform();
	GetWorld()->SpawnActor<ACollectable>(CollectableClass, Xform);
}

void ACustomGameMode::EndGame()
{
	bGameOver = true;

	if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
	{
		PC->SetPause(true);
	}
}

void ACustomGameMode::HandleCollected(class ACollectable* Collected, class APawn* CollectorPawn)
{
	if (bGameOver) return;
	if (!Collected || !CollectorPawn) return;

	if (APlayerController* PC = Cast<APlayerController>(CollectorPawn->GetController()))
	{
		if (ACustomPlayerState* PS = PC->GetPlayerState<ACustomPlayerState>())
		{
			PS->AddScoreValue(1);
			Collected->Destroy();
			SpawnCollectableAtRandomPoint();
		}
	}
}
//void ACustomGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
//{
//	Super::InitGame(MapName, Options, ErrorMessage);
//
//	UE_LOG(LogTemp, Warning, TEXT("[GameMode::InitGame] Map=%s, Options=%s"), *MapName, *Options);
//}
//
//void ACustomGameMode::InitGameState()
//{
//	Super::InitGameState();
//
//	UE_LOG(LogTemp, Warning, TEXT("[GameMode::InitGameState]"));
//}
//
//void ACustomGameMode::PostLogin(APlayerController* NewPlayer)
//{
//	Super::PostLogin(NewPlayer);
//
//	UE_LOG(LogTemp, Warning, TEXT("[GameMode::PostLogin] New player controller joined: %s"),
//		*GetNameSafe(NewPlayer));
//}
//
//void ACustomGameMode::StartPlay()
//{
//	Super::StartPlay();
//
//	UE_LOG(LogTemp, Warning, TEXT("[GameMode::StartPlay] Match flow entering Play on server."));
//	
//	if(ACustomGameState* gs = GetGameState<ACustomGameState>())
//	{
//		UE_LOG(LogTemp, Warning, TEXT("  - GameState: %s"), *gs->GetClass()->GetName());
//		
//		for(APlayerState* ps : gs->PlayerArray)
//		{
//			UE_LOG(LogTemp, Warning, TEXT("  - PlayerState: %s (PlayerName=%s)"), *ps->GetClass()->GetName(), *ps->GetPlayerName());
//		}
//	}
//}