// Iozhik inc 2018. All rights reserved

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto CurrentTime = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("Elevating %f at %f"), RelativeSpeed, CurrentTime);
}



