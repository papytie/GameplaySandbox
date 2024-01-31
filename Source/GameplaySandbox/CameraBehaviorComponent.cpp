// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraBehaviorComponent.h"
#include "CameraSettingsComponent.h"
#

// Sets default values for this component's properties
UCameraBehaviorComponent::UCameraBehaviorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Settings = CreateDefaultSubobject<UCameraSettingsComponent>("Settings");
}


// Called when the game starts
void UCameraBehaviorComponent::BeginPlay()
{
	Super::BeginPlay();
	InitItem();

	
}


// Called every frame
void UCameraBehaviorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Debug();

}

void UCameraBehaviorComponent::InitItem()
{
	Settings.Get()->InitCam(GetOwner()->GetComponentByClass<UCameraComponent>());
	GetWorld()->GetFirstPlayerController()->SetViewTarget(GetOwner());
}

void UCameraBehaviorComponent::Enable()
{
}

void UCameraBehaviorComponent::Disable()
{
}

void UCameraBehaviorComponent::Debug()
{
}

void UCameraBehaviorComponent::MoveTo()
{
}

void UCameraBehaviorComponent::RotateTo()
{
}

