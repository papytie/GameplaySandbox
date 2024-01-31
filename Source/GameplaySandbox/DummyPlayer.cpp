// Fill out your copyright notice in the Description page of Project Settings.


#include "DummyPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/SplineComponent.h"


// Sets default values
ADummyPlayer::ADummyPlayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	//SplineComponent = CreateDefaultSubobject<USplineComponent>("Spline");

	MidBezierPoint = CreateDefaultSubobject<USceneComponent>("MidPoint");
	BezierStart = CreateDefaultSubobject<USceneComponent>("StartPoint");
	BezierEnd = CreateDefaultSubobject<USceneComponent>("EndPoint");
	MidBezierPoint->SetupAttachment(RootComponent);
	BezierStart->SetupAttachment(RootComponent);
	BezierEnd->SetupAttachment(RootComponent);
	//SplineComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(RootComponent);
	MeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADummyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ADummyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DrawDebug();

	CameraLookAt(GetActorLocation());

	IncreaseLerpTime();
	CameraBezierMovement();

}


void ADummyPlayer::CameraLookAt(FVector Target)
{
	FVector DirectionToTarget = MeshComponent->GetRelativeLocation() - CameraComponent->GetRelativeLocation();
	DirectionToTarget.Normalize();

	FQuat NewRotation = FQuat::FindBetweenVectors(MeshComponent->GetForwardVector(), DirectionToTarget);

	FVector NewRotationVector = NewRotation.ToRotationVector();
	
	if (NewRotationVector == DirectionToTarget) return;

	CameraComponent->SetRelativeRotation(NewRotation.Rotator());
}

void ADummyPlayer::CameraBezierMovement()
{
	CameraComponent->SetRelativeLocation(
		QuadraticBezierMovement(BezierStart->GetRelativeLocation(), 
								MidBezierPoint->GetRelativeLocation(), 
								BezierEnd->GetRelativeLocation(), LerpTime));
}

FVector ADummyPlayer::QuadraticBezierMovement(FVector Start, FVector MidPoint, FVector End, float Time)
{
	//B(t) = (1 - t)2P0 + 2(1 - t)tP1 + t2P2, 0 < t < 1
	
	return ((1 - Time)*(1 - Time)) * Start + 2 * (1 - Time) * Time * MidPoint + (Time * Time) * End;

}

void ADummyPlayer::IncreaseLerpTime()
{
	if (!AutoLoop)return;
	LerpTime += GetWorld()->DeltaTimeSeconds;
	if (LerpTime >= 1)
		LerpTime = 0;
}

void ADummyPlayer::DrawDebug()
{
	DrawDebugBox(GetWorld(), BezierStart->GetRelativeLocation(), FVector(100), FColor::Blue);
	DrawDebugBox(GetWorld(), BezierEnd->GetRelativeLocation(), FVector(100), FColor::Red);
	DrawDebugBox(GetWorld(), MidBezierPoint->GetRelativeLocation(), FVector(100), FColor::Green);
}