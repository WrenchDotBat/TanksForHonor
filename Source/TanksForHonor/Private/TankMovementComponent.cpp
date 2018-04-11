// Iozhik inc 2018. All rights reserved

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::MoveForward(float Throw)
{
	LeftTrack->SetThrottle(Throw / 2);
	RightTrack->SetThrottle(Throw / 2);
}

void UTankMovementComponent::MoveRight(float Throw)
{
	LeftTrack->SetThrottle(Throw / 2);
	RightTrack->SetThrottle(-Throw / 2);
}

void UTankMovementComponent::Init(UTankTrack* LeftToSet, UTankTrack* RightToSet)
{
	if (!LeftToSet || !RightToSet) return;
	LeftTrack = LeftToSet;
	RightTrack = RightToSet;
}


