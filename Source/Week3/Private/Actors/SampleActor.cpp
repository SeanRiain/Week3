// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/SampleActor.h"

// Sets default values
ASampleActor::ASampleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASampleActor::ApplyDamage(float amount)
{
}

float ASampleActor::GetHealth()
{
	return 0.0f;
}

void ASampleActor::TakeHit_Implementation(FVector& hitLocation)
{
}

