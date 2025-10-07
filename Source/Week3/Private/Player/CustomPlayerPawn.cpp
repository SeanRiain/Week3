// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CustomPlayerPawn.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
ACustomPlayerPawn::ACustomPlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("[Character::Ctor] Character constructed (server; replicated to clients)."));

	//Create a sphere collider component
	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	//100cm radius
	Sphere->SetSphereRadius(100.0f);
	Sphere->SetCollisionProfileName(TEXT("Pawn"));
     
	//Creating a floating pawn movement component
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	//set maximum speed
	Movement->MaxSpeed = 600.0f;

	//we will rotate our controller when looking around
	//we will apply this rotation to our player pawn
	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = true;
}

// Called when the game starts or when spawned
void ACustomPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("[Character::BeginPlay] Character ready in world."));

	//get the controller to possess this pawn
	if (APlayerController* controller = Cast<APlayerController>(GetController()))
	{
		//Set the inputcontext for this pawn, if this pawn is controller by a local player
		if (ULocalPlayer* localPlayer = controller->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* input = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(localPlayer))
			{
				input->AddMappingContext(GameInputContext, 0);
			}
		}
	}
}

void ACustomPlayerPawn::OnMove(const FInputActionValue& Value)
{
	FVector2D MovementVector = Value.Get<FVector2D>();

	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);

}

void ACustomPlayerPawn::OnLook(const FInputActionValue& Value)
{
	FVector2D LookVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

// Called to bind functionality to input
void ACustomPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* inputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			//when IA_Move is triggered, call OnMove
			inputComp->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACustomPlayerPawn::OnMove);
		}

		if (LookAction)
		{
			//when IA_Move is triggered, call OnLook
			inputComp->BindAction(LookAction, ETriggerEvent::Triggered, this, &ACustomPlayerPawn::OnLook);
		}
	}
}