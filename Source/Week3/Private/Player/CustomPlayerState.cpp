// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CustomPlayerState.h"

ACustomPlayerState::ACustomPlayerState()
{
	SetPlayerName("Neil Gannon");
	
	UE_LOG(LogTemp, Warning, TEXT("[PlayerState::Ctor] PS  %s constructed (server + clients)."), 
		*GetPlayerName());
}

