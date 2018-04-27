// Iozhik inc 2018. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

class AProjectile;

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};

class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKSFORHONOR_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Aiming;

public:	
	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Init(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector AimLocation);

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 10000.f;

	UFUNCTION(BlueprintCallable, Category = "Controls")
		void Fire();

	UPROPERTY(EditAnywhere, Category = "Setup")
		float ReloadTime = 3.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UFUNCTION(BlueprintCallable, Category = "Firing")
		int GetRoundsLeft() const;

private:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	bool IsBarrelMoving();
	FVector AimDirection;
	UTankBarrel * Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrel(FVector AimDirection);

	float LastFireTime = 0.f;

	int RoundsLeft = 3;
};
