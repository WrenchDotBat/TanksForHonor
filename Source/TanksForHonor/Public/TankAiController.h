// Iozhik inc 2018. All rights reserved

#pragma once

#include "Tank.h"
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

public:
	virtual void BeginPlay() override;

	ATank* GetTankAiController() const;
	
	ATank* GetPlayerController() const;
	
};
