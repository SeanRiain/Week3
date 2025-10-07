// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CustomGameSession.h"


// Sets default values
ACustomGameSession::ACustomGameSession()
{
	PrimaryActorTick.bCanEverTick = true;
	MaxPlayers = 2;
	MaxSpectators = 0;
	
	UE_LOG(LogTemp, Warning, TEXT("[GameSession::Ctor] GameSession constructed (server-only)."));
}

FString ACustomGameSession::ApproveLogin(const FString& Options)
{
	
	return Super::ApproveLogin(Options);
}
