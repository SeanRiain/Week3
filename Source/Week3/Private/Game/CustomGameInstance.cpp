// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/CustomGameInstance.h"

void UCustomGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("[GameInstance::Init] GI created and initialized."));
}

void UCustomGameInstance::Shutdown()
{
	Super::Shutdown();

	UE_LOG(LogTemp, Warning, TEXT("[GameInstance::Init] GI is shutting down."));
}
