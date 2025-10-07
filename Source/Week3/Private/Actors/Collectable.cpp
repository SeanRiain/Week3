// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Collectable.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Game/CustomGameMode.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->InitSphereRadius(75.f);
	Sphere->SetCollisionObjectType(ECC_WorldDynamic);
	SetRootComponent(Sphere);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}
	void ACollectable::NotifyActorBeginOverlap(AActor* OtherActor)
	{
		Super::NotifyActorBeginOverlap(OtherActor);

		APawn* OverLappingPawn = Cast<APawn>(OtherActor);
		if (!OverLappingPawn) return;

		Destroy();
	}
// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
}

