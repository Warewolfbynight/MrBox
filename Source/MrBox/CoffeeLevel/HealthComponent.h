// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class ACoffeeLevelGameModeBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MRBOX_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	

private:

	UPROPERTY(EditAnywhere)
		float DefaultHealth = 100.0f;

		float Health = 0.0f;

		ACoffeeLevelGameModeBase* GameModeRef;

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
		void TakeDamage(AActor* DmagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
		
};
