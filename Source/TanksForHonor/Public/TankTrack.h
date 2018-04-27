// Iozhik inc 2018. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 *
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKSFORHONOR_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
		void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly)
		float TrackMaxDrivingForce = 400000;

private:
	UTankTrack();

	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	void DriveTrack();

	float CurrentThrottle = 0;
};
