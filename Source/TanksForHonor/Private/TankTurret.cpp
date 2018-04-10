// Iozhik inc 2018. All rights reserved

#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	auto RotationChange = FMath::Clamp<float>(RelativeSpeed, -1, 1) * MaxDegreesPerSeconds * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}


