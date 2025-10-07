// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"
#include "CustomGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WEEK3_API UCustomGameInstance : public UPlatformGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Shutdown() override;
};
