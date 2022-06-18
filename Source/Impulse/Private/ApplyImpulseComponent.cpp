// Fill out your copyright notice in the Description page of Project Settings.


#include "ApplyImpulseComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UApplyImpulseComponent::UApplyImpulseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called every frame
void UApplyImpulseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FHitResult Hit;

	const FVector Start = GetComponentLocation();
	FVector End = Start + GetComponentRotation().Vector() * TraceDistance;

	FCollisionQueryParams TraceParams;
	bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);

	if (bHit)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 0.1f);

		UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(Hit.GetActor()->GetRootComponent());
		if (MeshComp && Hit.GetActor()->IsRootComponentMovable())
		{
			FVector Forward = this->GetForwardVector();
			MeshComp->AddImpulse(Forward * ImpulseForce * MeshComp->GetMass());
		}
	}

}

