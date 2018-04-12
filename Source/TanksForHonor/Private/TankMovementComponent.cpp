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

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto MoveVelocityNormal = MoveVelocity.GetSafeNormal();
	
	MoveForward(FVector::DotProduct(TankForward, MoveVelocityNormal));

	MoveRight(FVector::CrossProduct(TankForward, MoveVelocityNormal).Z);
}

void UTankMovementComponent::Init(UTankTrack* LeftToSet, UTankTrack* RightToSet)
{
	if (!ensure(LeftToSet && RightToSet)) return;
	LeftTrack = LeftToSet;
	RightTrack = RightToSet;
}


