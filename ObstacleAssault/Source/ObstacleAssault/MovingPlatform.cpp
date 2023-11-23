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

	StartLocation = GetActorLocation();

	//FString MyString = GetName();

	//UE_LOG(LogTemp, Display, TEXT("Obj name: %s"), *MyString);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime){
	

	if(ShouldReturn()){
		//float OverShoot = PlatformDist - MovedDistance;
		//UE_LOG(LogTemp, Display, TEXT("%s Overshoot: %f"), *(GetName()), OverShoot);

		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MovedDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity *= -1;
	}
	else{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation += PlatformVelocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime){
	//UE_LOG(LogTemp, Display, TEXT("DeltaTime: %f"), DeltaTime);
	
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldReturn() const{
	return GetDistanceMoved() > MovedDistance;
}

float AMovingPlatform::GetDistanceMoved() const{
	return FVector::Dist(StartLocation, GetActorLocation());
}