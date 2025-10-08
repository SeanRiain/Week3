// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CustomPlayerState.h"

ACustomPlayerState::ACustomPlayerState()
{
	SetPlayerName("Neil Gannon");
	CurrentScore = 0;
	
	UE_LOG(LogTemp, Warning, TEXT("[PlayerState::Ctor] PS  %s constructed (server + clients)."), *GetPlayerName());
}

int32 ACustomPlayerState::GetScoreValue() const
{
	return CurrentScore;
}

void ACustomPlayerState::AddScoreValue(int32 amount)
{
	CurrentScore += amount;
}
