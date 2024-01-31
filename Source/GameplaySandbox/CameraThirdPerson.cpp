// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraThirdPerson.h"
#include "CameraSettingsComponent.h"
#include <Kismet/KismetMathLibrary.h>

UCameraThirdPerson::UCameraThirdPerson()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UCameraThirdPerson::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UCameraThirdPerson::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveTo();
	RotateTo();

}

void UCameraThirdPerson::MoveTo()
{
	if (!Settings->GetCanMove())return;
	FVector Location = UKismetMathLibrary::VInterpTo_Constant(GetOwner()->GetActorLocation(), 
															  Settings->GetOffset().GetOffset(Settings->GetTarget()), 
															  GetWorld()->DeltaTimeSeconds, 
															  Settings->GetMoveSpeed());
	GetOwner()->SetActorLocation(Location);
}

void UCameraThirdPerson::RotateTo()
{
	if (!Settings->GetCanRotate())return;
	FRotator Rotation = UKismetMathLibrary::FindLookAtRotation(GetOwner()->GetActorLocation(), 
															   Settings->GetTargetPosition());
	FRotator NewRotation = UKismetMathLibrary::RInterpTo_Constant(GetOwner()->GetActorRotation(), 
																  Rotation, 
																  GetWorld()->DeltaTimeSeconds, 
																  Settings->GetRotationSpeed());
	GetOwner()->SetActorRotation(NewRotation);
}

void UCameraThirdPerson::Debug()
{
	if (!Settings || !Settings->GetTarget())return;
	DrawDebugSphere(GetWorld(), Settings->GetOffset().GetOffset(Settings->GetTarget()), 25, 25, FColor::Green);
	DrawDebugLine(GetWorld(), Settings->GetCurrentPosition(), Settings->GetOffset().GetOffset(Settings->GetTarget()), FColor::Red);
}

