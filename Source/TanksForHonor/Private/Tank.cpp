// Iozhik inc 2018. All rights reserved

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const & DamageEvent, AController * EventInstigator, AActor * DamageCauser)
{
	int DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int DamageToApply = FMath::Clamp(DamagePoints, 0, StartingHealth);
	
	CurrentHealth -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Damage: %i   Health: %i"), DamageToApply, CurrentHealth);
	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("DEAD"));
	}

	return DamageToApply;
}

float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}


