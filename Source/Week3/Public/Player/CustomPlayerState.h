// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CustomPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class WEEK3_API ACustomPlayerState : public APlayerState
{
	GENERATED_BODY()

	
public:
	ACustomPlayerState();

	UFUNCTION(BlueprintCallable)
	int32 GetScoreValue() const;

	UFUNCTION()
	void AddScoreValue(int32 amount);

protected:
	int32 CurrentScore;
};
