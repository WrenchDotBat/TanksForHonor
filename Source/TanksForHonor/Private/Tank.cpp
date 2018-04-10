// Iozhik inc 2018. All rights reserved

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h" 


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!barrel) return;
	UE_LOG(LogTemp, Warning, TEXT("SHOT"));
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		barrel->GetSocketLocation(FName("Projectile")),
		barrel->GetSocketRotation(FName("Projectile"))
		);
	Projectile->Launch(LaunchSpeed);
}

void ATank::SetBarrelRef(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrel(BarrelToSet);
	barrel = BarrelToSet;
}

void ATank::SetTurretRef(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurret(TurretToSet);
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

