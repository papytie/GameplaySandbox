// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DummyPlayer.generated.h"

class UCameraComponent;
class USplineComponent;
UCLASS()
class GAMEPLAYSANDBOX_API ADummyPlayer : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) TObjectPtr<UCameraComponent> CameraComponent = nullptr;
	//UPROPERTY(EditAnywhere) TObjectPtr<USplineComponent> SplineComponent = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UStaticMeshComponent> MeshComponent = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<USceneComponent> MidBezierPoint = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<USceneComponent> BezierStart = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<USceneComponent> BezierEnd = nullptr;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0", ClampMax = "1")) float LerpTime = 0;
	UPROPERTY(EditAnywhere) bool AutoLoop = false;
	
public:	
	// Sets default values for this actor's properties
	ADummyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void CameraLookAt(FVector Target);
	void CameraBezierMovement();
	FVector QuadraticBezierMovement(FVector Start, FVector MidPoint, FVector End, float Time);
	void IncreaseLerpTime();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DrawDebug();

};
