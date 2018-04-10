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

public:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	ATank* GetTank() const;
	
	ATank* GetPlayerController() const;
	
};
