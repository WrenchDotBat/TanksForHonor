// Iozhik inc 2018. All rights reserved

#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTurret.h"


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
	PrimaryComponentTick.bCanEverTick = true;
	LastFireTime = GetWorld()->GetTimeSeconds();
}

void UTankAimingComponent::Fire()
{
	if (FiringState != EFiringState::Reloading) {
		if (!ensure(Barrel && ProjectileBlueprint)) return;
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		if (!ensure(Projectile)) {
			UE_LOG(LogTemp, Error, TEXT("Projectile_BP not set"));
			return;
		}
		Projectile->Launch(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}

EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;
}

void UTankAimingComponent::Init(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	if (!ensure(BarrelToSet && TurretToSet)) return;
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector AimLocation)
{
	if (!ensure(Barrel)) return;
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
		AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
}

int UTankAimingComponent::GetRoundsLeft() const
{
	return RoundsLeft;
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if ((GetWorld()->GetTimeSeconds() - LastFireTime) < ReloadTime)
		FiringState = EFiringState::Reloading;
	else if (IsBarrelMoving())
		FiringState = EFiringState::Aiming;
	else
		FiringState = EFiringState::Locked;
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) return false;
	auto BarrelForward = Barrel->GetForwardVector();
	return !BarrelForward.Equals(AimDirection, 0.01);
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!ensure(Barrel && Turret)) return;
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch);
	if (FMath::Abs(DeltaRotator.Yaw) < 180)
		Turret->Rotate(DeltaRotator.Yaw);
	else
		Turret->Rotate(-DeltaRotator.Yaw);
}

