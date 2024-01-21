// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"

#include "PlatformerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GAMEPLAYSANDBOX_API APlatformerCharacter : public ACharacter
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere) TObjectPtr<USpringArmComponent> springArmComponent = nullptr;
		UPROPERTY(EditAnywhere) TObjectPtr<UCameraComponent> cameraComponent = nullptr;

		UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> inputMove = nullptr;
		UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> inputRotation = nullptr;
		UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> inputJump = nullptr;
		UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> inputCrouch = nullptr;
		UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> inputSprint = nullptr;
		UPROPERTY(EditAnywhere) TObjectPtr<UInputMappingContext> imc = nullptr;

public:
	APlatformerCharacter();

protected:
	virtual void BeginPlay() override;
	void InitInputs();

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
