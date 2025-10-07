// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SampleActor.generated.h"

UCLASS(Blueprintable, BlueprintType)
class WEEK3_API ASampleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASampleActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sample")
	int32 Score;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sample")
	float Damage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sample")
	bool bHasKeyCard;

	UFUNCTION(BlueprintCallable)
	void ApplyDamage(float amount);

	UFUNCTION(BlueprintNativeEvent)
	void TakeHit(FVector& hitLocation);

	UFUNCTION(BlueprintCallable)
	float GetHealth();
};
