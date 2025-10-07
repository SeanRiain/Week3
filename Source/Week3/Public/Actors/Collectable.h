// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Collectable.generated.h"

UCLASS()
class WEEK3_API ACollectable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	class USphereComponent* Sphere;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* Mesh;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
