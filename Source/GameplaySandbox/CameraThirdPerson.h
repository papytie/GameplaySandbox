// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraBehaviorComponent.h"
#include "CameraThirdPerson.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPLAYSANDBOX_API UCameraThirdPerson : public UCameraBehaviorComponent
{
	GENERATED_BODY()
		

public:	
	UCameraThirdPerson();

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void MoveTo();
	virtual void RotateTo();
	void Debug();
		
};
