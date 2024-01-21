// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include <EnhancedInputSubsystems.h>

APlatformerCharacter::APlatformerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	springArmComponent = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	springArmComponent->SetupAttachment(RootComponent);
	cameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	cameraComponent->SetupAttachment(springArmComponent);

}

void APlatformerCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitInputs();
}

void APlatformerCharacter::InitInputs()
{
	ULocalPlayer* _localPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer();
	if (!_localPlayer) return;
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!_inputSystem)return;
	_inputSystem->AddMappingContext(imc, 0);
}

void APlatformerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

