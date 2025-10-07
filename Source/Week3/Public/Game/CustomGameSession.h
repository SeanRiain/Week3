// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "CustomGameSession.generated.h"

UCLASS()
class WEEK3_API ACustomGameSession : public AGameSession
{
	GENERATED_BODY()

public:
	ACustomGameSession();

	virtual FString ApproveLogin(const FString& Options) override;
};
