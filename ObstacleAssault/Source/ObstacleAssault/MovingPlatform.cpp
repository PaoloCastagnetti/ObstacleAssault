// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move the platform foreward
		// Get current location
	FVector CurrentLocation = GetActorLocation();
		// Add vector to that location
	CurrentLocation.X += 1;
		//Set the location
	SetActorLocation(CurrentLocation);
	//Send platform back if gone to far
		//Check how far we've moved
		// Reverse direction of motion if gone too far

}
