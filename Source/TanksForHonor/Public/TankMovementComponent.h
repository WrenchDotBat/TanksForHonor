// Iozhik inc 2018. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKSFORHONOR_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Init(UTankTrack* LeftToSet, UTankTrack* RightToSet);

	UFUNCTION(BlueprintCallable, Category = Input)
	void MoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Input)
	void MoveRight(float Throw);
	
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;


private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;

};
