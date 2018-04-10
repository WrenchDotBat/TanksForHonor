// Iozhik inc 2018. All rights reserved

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UTankAimingComponent::SetBarrel(UTankBarrel * BarrelToSet)
{
	if (!BarrelToSet) return;
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurret(UTankTurret * TurretToSet)
{
	if (!TurretToSet) return;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector AimLocation, float LaunchSpeed)
{
	if (!Barrel) return;
	//UE_LOG(LogTemp, Warning, TEXT("Located at: %s"), *AimLocation.ToString());
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		AimLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	)
		)
	{
		//DrawDebugLine(GetWorld(), StartLocation, AimLocation, FColor(0, 128, 0), false, 0.f, 0.f, 10.f);
		MoveBarrel(OutLaunchVelocity.GetSafeNormal());
	}
	//auto OurTankName = GetOwner()->GetName();
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	//UE_LOG(LogTemp, Warning, TEXT("Located at: %s"), *AimDirection.ToString());
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}

