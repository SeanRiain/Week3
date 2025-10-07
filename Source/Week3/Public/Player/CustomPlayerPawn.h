// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "InputAction.h"
#include "InputMappingContext.h"

#include "CustomPlayerPawn.generated.h"

UCLASS()
class WEEK3_API ACustomPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACustomPlayerPawn();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY (EditDefaultsOnly)
	UInputMappingContext* GameInputContext;

	UPROPERTY(EditDefaultsOnly)
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly)
	UInputAction* LookAction;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UPROPERTY(VisibleAnywhere)
	UFloatingPawnMovement* Movement;

	void OnMove(const FInputActionValue& Value);

	void OnLook(const FInputActionValue& Value);

};