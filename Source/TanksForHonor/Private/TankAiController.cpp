// Iozhik inc 2018. All rights reserved

#include "TankAiController.h"
#include "Tank.h"


void ATankAiController::BeginPlay() 
{
	Super::BeginPlay();
	AiTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ensure(PlayerTank && AiTank))
	{
		MoveToActor(PlayerTank, AcceptanceRadius);
		AiTank->AimAt(PlayerTank->GetActorLocation());
		AiTank->Fire();
	}
}

