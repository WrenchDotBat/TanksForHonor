// Iozhik inc 2018. All rights reserved

#pragma once

//#include "Tank.h" TODO DELETE
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class TANKSFORHONOR_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		float ScreenCrossHairLocationY = 0.33333f;

	UPROPERTY(EditAnywhere)
		float ScreenCrossHairLocationX = 0.5f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.f;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& WorldDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;
	
};
