// Iozhik inc 2018. All rights reserved

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{	
	auto Time = GetWorld()->GetTimeSeconds();

	auto ForceAppiled = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceAppiled, ForceLocation);
}


