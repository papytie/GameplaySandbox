// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraBehaviorComponent.generated.h"

class UCameraSettingsComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYSANDBOX_API UCameraBehaviorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere) FString id = "camera";
	UPROPERTY(EditAnywhere) TObjectPtr<UCameraSettingsComponent> Settings = nullptr;

public:	
	// Sets default values for this component's properties
	UCameraBehaviorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	virtual void InitItem();
	virtual void Enable();
	virtual void Disable();
	virtual void Debug();

	UFUNCTION()
	virtual void MoveTo();
	UFUNCTION()
	virtual void RotateTo();
		
};
