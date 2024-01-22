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


public:
	APlatformerCharacter();

protected:

	UPROPERTY(EditAnywhere) TObjectPtr<USpringArmComponent> SpringArmComponent = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UCameraComponent> CameraComponent = nullptr;

	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> InputActionMove = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> InputActionLook = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> InputActionSprint = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> InputActionJump = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputAction> InputActionCrouch = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformerCharacter|AnimationInputs")
	float LeftStickXValue = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformerCharacter|AnimationInputs")
	float LeftStickYValue = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformerCharacter|AnimationInputs")
	bool isSprinting = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformerCharacter|AnimationInputs")
	bool isJumping = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlatformerCharacter|AnimationInputs")
	bool isCrouching = false;

	virtual void BeginPlay() override;
	
	void InitIMC();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Jump(const FInputActionValue& Value);
	void Sprint(const FInputActionValue& Value);
	void Crouch(const FInputActionValue& Value);

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
