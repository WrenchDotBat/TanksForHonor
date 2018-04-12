// Iozhik inc 2018. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile;
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class TANKSFORHONOR_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Setup")
		UTankAimingComponent* TankAimingComponent = nullptr;

private:
	float LastFireTime = 0.f;

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Controls")
		void Fire();

	UPROPERTY(EditAnywhere, Category = "Setup")
		float ReloadTime = 3.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 10000.f;

	UTankBarrel* Barrel = nullptr;

};
