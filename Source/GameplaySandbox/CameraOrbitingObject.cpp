// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraOrbitingObject.h"
#include "Camera/CameraComponent.h"


// Sets default values
ACameraOrbitingObject::ACameraOrbitingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ACameraOrbitingObject::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ACameraOrbitingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LookAtTarget();

}

void ACameraOrbitingObject::LookAtTarget()
{
	if (CameraTarget->GetActorLocation() == GetActorLocation()) return;

	FVector DirectionToTarget = CameraTarget->GetActorLocation() - GetActorLocation();
	DirectionToTarget.Normalize();

	FQuat NewRotation = FQuat::FindBetweenVectors(GetActorForwardVector(), DirectionToTarget);
	
	FVector NewRotationVector = NewRotation.ToRotationVector();
	if (NewRotationVector == DirectionToTarget) return;

	SetActorRotation(NewRotation.Rotator());
}
