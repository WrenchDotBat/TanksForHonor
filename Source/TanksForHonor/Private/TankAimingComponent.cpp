// Iozhik inc 2018. All rights reserved

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::SetBarrel(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector AimLocation, float LaunchSpeed)
{
	if (!Barrel) return;
	FVector OutLaunchVelocity = FVector(1.f);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		AimLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	)
		)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Aiming: %s"), *AimDirection);
		MoveBarrel(OutLaunchVelocity.GetSafeNormal());
	}
	//auto OurTankName = GetOwner()->GetName();
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	Barrel->Elevate(5.f);
}

