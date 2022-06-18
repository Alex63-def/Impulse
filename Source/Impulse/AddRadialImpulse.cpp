// Fill out your copyright notice in the Description page of Project Settings.


#include "AddRadialImpulse.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UAddRadialImpulse::UAddRadialImpulse()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAddRadialImpulse::BeginPlay()
{
	Super::BeginPlay();

	// обнаружим все обекты к которым применим силу
	TArray<FHitResult> HitArray;
	
	//начало и конец совпадают так как имеется ввиду сфера целиком, что окажется внутри нее
	const FVector Start = this->GetComponentLocation();
	const FVector End = Start;

	// сфера считывающая столкновения - есть капсула и бокс
	const FCollisionShape SphereShape = FCollisionShape::MakeSphere(Radius);

	const bool bSweepHit = GetWorld()->SweepMultiByChannel(HitArray, Start, End, FQuat::Identity, ECC_WorldStatic, SphereShape);

	DrawDebugSphere(GetWorld(), Start, Radius, 50, FColor::Orange, true);

	// проверка на возможность передать импульс
	if (bSweepHit)
	{
		for (const FHitResult HitResult : HitArray)
		{
			UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(HitResult.GetActor()->GetRootComponent());
			if (MeshComp)
			{
				MeshComp->AddRadialImpulse(Start, Radius, Strength, RIF_Linear, true);
			}
		}
	}
}

