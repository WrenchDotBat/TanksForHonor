// Iozhik inc 2018. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta=(BlueprintSpawnableComponent) )
class TANKSFORHONOR_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float Degrees);
	
private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSeconds = 20.f;
	UPROPERTY(EditAnywhere)
		float MaxElevation = 40.f;
	UPROPERTY(EditAnywhere)
		float MinElevation = 0.f;
	
};
