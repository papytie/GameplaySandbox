// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraOrbitingObject.generated.h"

class UCameraComponent;

UCLASS()
class GAMEPLAYSANDBOX_API ACameraOrbitingObject : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent = nullptr;

	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> CameraTarget = nullptr;
	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> OrbitalPoint = nullptr;


public:	
	// Sets default values for this actor's properties
	ACameraOrbitingObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void LookAtTarget();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
