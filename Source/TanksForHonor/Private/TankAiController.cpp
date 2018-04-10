// Iozhik inc 2018. All rights reserved

#include "TankAiController.h"
#include "Tank.h"


void ATankAiController::BeginPlay() 
{
	Super::BeginPlay();
	auto AiTank = GetTank();
	auto PlayerTank = GetPlayerController();
	if (!AiTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI controller not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank AI controller: %s"), *(AiTank->GetName()));
	}
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI NOT found player!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI %s found player!"), *(PlayerTank->GetName()));
	}
}

void ATankAiController::Tick(float DeltaTime) 
{
	Super::Tick(DeltaTime);
	if (GetPlayerController())
	{
		GetTank()->AimAt(GetPlayerController()->GetActorLocation());
		GetTank()->Fire();
	}
}

ATank* ATankAiController::GetTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAiController::GetPlayerController() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}




