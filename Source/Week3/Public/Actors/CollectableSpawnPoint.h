// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectableSpawnPoint.generated.h"

UCLASS()
class WEEK3_API ACollectableSpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableSpawnPoint();

protected:
	UPROPERTY()
	USceneComponent* Root;

};
