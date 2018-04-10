// Iozhik inc 2018. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

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

public:	

	void SetBarrel(UTankBarrel* BarrelToSet);

	void SetTurret(UTankTurret* TurretToSet);

	void AimAt(FVector AimLocation, float LaunchSpeed);

private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;
	
	void MoveBarrel(FVector AimDirection);
};
