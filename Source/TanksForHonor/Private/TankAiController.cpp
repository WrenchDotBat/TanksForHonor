// Iozhik inc 2018. All rights reserved

#include "TankAimingComponent.h"
#include "TankAiController.h"


void ATankAiController::BeginPlay() 
{
	Super::BeginPlay();
}

void ATankAiController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto AiTank = GetPawn();
	UE_LOG(LogTemp, Warning, TEXT("Moving called"));
	if (!ensure(PlayerTank && AiTank)) return;
	MoveToActor(PlayerTank, AcceptanceRadius);
	auto AimingComponent = AiTank->FindComponentByClass<UTankAimingComponent>();
	//if (!ensure(AimingComponent)) return;
	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	AimingComponent->Fire();
}

