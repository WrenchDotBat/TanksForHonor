// Iozhik inc 2018. All rights reserved

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();
	auto tempTank = GetTankPlayerController();
	if (!tempTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank player controller not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank player controller: %s"), *(tempTank->GetName()));
	}
}

ATank* ATankPlayerController::GetTankPlayerController() const
{
	return Cast<ATank>(GetPawn());
}


