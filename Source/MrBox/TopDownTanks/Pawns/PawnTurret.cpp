// Fill out your copyright notice in the Description page of Project Settings.


#include "MrBox/TopDownTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"

void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void APawnTurret::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}
	RotateTurret(PlayerPawn->GetActorLocation());

}
void APawnTurret::CheckFireCondition()
{

	// if Player == null || Is Dead Then bail!
	{
		if (!PlayerPawn || !PlayerPawn->GetIsPlayerAlive())
		{
			return;
		}

	}
	// If Player IS in range then fire!
	if (ReturnDistanceToPlayer() <= FireRange)
	{
		//fire
		Fire();
	}
}

float APawnTurret::ReturnDistanceToPlayer()
{
	if (!PlayerPawn)
	{
		return 0.f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());

}