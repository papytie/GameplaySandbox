// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"

APlatformerCharacter::APlatformerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);

}

void APlatformerCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitIMC();
}

void APlatformerCharacter::InitIMC()
{
	if (ULocalPlayer* LocalPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer())
	{
		UE_LOG(LogTemp, Warning, TEXT("LocalPlayer initialised"));
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			UE_LOG(LogTemp, Warning, TEXT("Subsystem initialised"));
			Subsystem->AddMappingContext(InputMappingContext, 0);
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("Subsystem error"));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("LocalPlayer error"));

}

void APlatformerCharacter::Move(const FInputActionValue& Value)
{
	GetWorld()->GetFirstPlayerController()->SetControlRotation(GetActorRotation()); //Align PlayerController Rotation to ActorRotation
	
	const FVector2D CurrentValue = Value.Get<FVector2D>();
	float XAxis = CurrentValue.X;
	float YAxis = CurrentValue.Y;
	UE_LOG(LogTemp, Warning, TEXT("XAxis value : %f"), XAxis);
	UE_LOG(LogTemp, Warning, TEXT("YAxis value : %f"), YAxis);
	LeftStickXValue = XAxis; //Set variable for animation
	
	bUseControllerRotationYaw = XAxis > 0.2f || XAxis < -0.2f ? true : false; //Change controller acces to edit RootMotion Rotation when go forward
	if (bUseControllerRotationYaw)
		AddControllerYawInput(YAxis); //Add Custom Rotation or (below)
	else LeftStickYValue = YAxis; //Set variable for animation
}

void APlatformerCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D CurrentValue = Value.Get<FVector2D>();
	float XAxis = CurrentValue.X;
	float YAxis = CurrentValue.Y;

}

void APlatformerCharacter::Jump(const FInputActionValue& Value)
{
	const bool CurrentValue = Value.Get<bool>();
	if (CurrentValue)
	{
		UE_LOG(LogTemp, Warning, TEXT("Jump Input"));
	}
}

void APlatformerCharacter::Sprint(const FInputActionValue& Value)
{
	isSprinting = Value.Get<bool>() ? true : false;
}

void APlatformerCharacter::Crouch(const FInputActionValue& Value)
{
	const bool CurrentValue = Value.Get<bool>();
	if (CurrentValue)
	{
		UE_LOG(LogTemp, Warning, TEXT("Crouch Input"));
	}
}

void APlatformerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InputActionMove, ETriggerEvent::Triggered, this, &APlatformerCharacter::Move);
		EnhancedInputComponent->BindAction(InputActionMove, ETriggerEvent::Completed, this, &APlatformerCharacter::Move);
		EnhancedInputComponent->BindAction(InputActionLook, ETriggerEvent::Triggered, this, &APlatformerCharacter::Look);
		EnhancedInputComponent->BindAction(InputActionLook, ETriggerEvent::Completed, this, &APlatformerCharacter::Look);
		EnhancedInputComponent->BindAction(InputActionJump, ETriggerEvent::Started, this, &APlatformerCharacter::Jump);
		EnhancedInputComponent->BindAction(InputActionSprint, ETriggerEvent::Started, this, &APlatformerCharacter::Sprint);
		EnhancedInputComponent->BindAction(InputActionSprint, ETriggerEvent::Completed, this, &APlatformerCharacter::Sprint);
		EnhancedInputComponent->BindAction(InputActionCrouch, ETriggerEvent::Started, this, &APlatformerCharacter::Crouch);
	}

}

