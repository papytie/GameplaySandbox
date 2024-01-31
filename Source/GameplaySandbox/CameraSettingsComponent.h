// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"
#include "CameraSettingsComponent.generated.h"

USTRUCT()
struct FOffset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere) float XOffset = 0;
	UPROPERTY(EditAnywhere) float YOffset = 0;
	UPROPERTY(EditAnywhere) float ZOffset = 0;
	UPROPERTY(EditAnywhere) bool IsLocal = false;

	FVector GetOffset(AActor* TargetActor)
	{
		if (!TargetActor)return FVector::ZeroVector;
		return IsLocal ? LocalOffset(TargetActor) : WorldOffset(TargetActor);
	}

	FVector LocalOffset(AActor* TargetActor)
	{
		if (!TargetActor)return FVector::ZeroVector;
		FVector X = TargetActor->GetActorForwardVector() * XOffset;
		FVector Y = TargetActor->GetActorRightVector() * YOffset;
		FVector Z = TargetActor->GetActorUpVector() * ZOffset;
		return /*TargetActor->GetActorLocation() +*/ X + Y + Z;
	}

	FVector WorldOffset(AActor* TargetActor)
	{
		if (!TargetActor)return FVector::ZeroVector;
		return TargetActor->GetActorLocation() + FVector(XOffset, YOffset, ZOffset);
	}
};

class UCameraComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYSANDBOX_API UCameraSettingsComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere) TObjectPtr<AActor> TargetActor = nullptr;
	UPROPERTY(EditAnywhere) TObjectPtr<UCameraComponent> CameraRender = nullptr;
	UPROPERTY(EditAnywhere) float MoveSpeed = 50;
	UPROPERTY(EditAnywhere) float RotationSpeed = 50;
	UPROPERTY(EditAnywhere) bool CanRotate = true;
	UPROPERTY(EditAnywhere) bool CanMove = true;
	UPROPERTY(EditAnywhere) FOffset Offset = FOffset();

public:
	AActor* GetTarget() { return TargetActor; }
	UCameraComponent* GetCameraRender() { return CameraRender; }
	FVector GetTargetPosition() { return TargetActor ? TargetActor->GetActorLocation() : FVector(0); }
	FVector GetCurrentPosition() { return GetOwner()->GetActorLocation(); }
	FRotator GetTargetRotation() { return TargetActor ? TargetActor->GetActorRotation() : FRotator(0); }
	FRotator GetCurrentRotation() { return GetOwner()->GetActorRotation(); }
	float GetMoveSpeed() { return MoveSpeed; }
	float GetRotationSpeed() { return RotationSpeed; }
	float GetCanMove() { return CanMove; }
	float GetCanRotate() { return CanRotate; }
	FOffset& GetOffset() { return Offset; }

public:	
	UCameraSettingsComponent();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void SetCanMove(bool Value);
	void SetCanRotate(bool Value);
	void SetCameraStatus(bool Value);
	void InitCam(UCameraComponent* Camera);
};
