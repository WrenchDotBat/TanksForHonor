// Iozhik inc 2018. All rights reserved

#pragma once

//#include "Tank.h" TODO DELETE
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAiController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class TANKSFORHONOR_API ATankAiController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* AiTank = nullptr;
	ATank* PlayerTank = nullptr;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	float AcceptanceRadius = 3000.f;
};
