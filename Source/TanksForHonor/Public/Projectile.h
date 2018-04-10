// Iozhik inc 2018. All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class TANKSFORHONOR_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UProjectileMovementComponent* MovementComponent = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Launch(float Speed);
	
};
