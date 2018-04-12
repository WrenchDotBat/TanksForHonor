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
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) return;
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!ensure(Barrel)) return;
	bool isReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTime; 
	if (isReloaded) {
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

