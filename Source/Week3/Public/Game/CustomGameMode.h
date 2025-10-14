// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CustomGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WEEK3_API ACustomGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACustomGameMode();

	void HandleCollected(class ACollectable* Collected, class APawn* CollectorPawn);

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	int32 ScoreToWin;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class ACollectable> CollectableClass;

	UPROPERTY()
	TArray<class ACollectableSpawnPoint*> SpawnPoints;

	int32 LastSpawnIndex;

	bool bGameOver;

	void SpawnCollectableAtRandomPoint();

	void EndGame();

	void GatherSpawnPoints();

	//virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	//virtual void InitGameState() override;
	//virtual void PostLogin(APlayerController* NewPlayer) override;
	//virtual void StartPlay() override;
};
