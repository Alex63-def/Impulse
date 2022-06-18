// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "AddRadialImpulse.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class IMPULSE_API UAddRadialImpulse : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAddRadialImpulse();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// радиус и сила
	UPROPERTY(EditAnywhere, Category = "Forces")
		float Radius = 500.0f;

	UPROPERTY(EditAnywhere, Category = "Forces")
		float Strength = 2000.0f;
};
