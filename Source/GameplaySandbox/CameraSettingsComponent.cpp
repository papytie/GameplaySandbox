// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraSettingsComponent.h"

UCameraSettingsComponent::UCameraSettingsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

}


void UCameraSettingsComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UCameraSettingsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UCameraSettingsComponent::SetCanMove(bool Value)
{
	CanMove = Value;
}

void UCameraSettingsComponent::SetCanRotate(bool Value)
{
	CanRotate = Value;
}

void UCameraSettingsComponent::SetCameraStatus(bool Value)
{
	CameraRender->SetActive(Value);
}

void UCameraSettingsComponent::InitCam(UCameraComponent* Camera)
{
	if (!Camera)return;
	CameraRender = Camera;
}

