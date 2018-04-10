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

	UTankAimingComponent* TankAimingComponent = nullptr;

private: 
	UTankBarrel*  barrel = nullptr;

public:	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Controls)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelRef(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretRef(UTankTurret* TurretToSet);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000.f;
	
};
