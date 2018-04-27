// Iozhik inc 2018. All rights reserved

#pragma once

//#include "Tank.h" TODO DELETE
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

/**
 * 
 */
UCLASS()
class TANKSFORHONOR_API ATankAiController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Setup")
	float AcceptanceRadius = 3000.f;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

};
