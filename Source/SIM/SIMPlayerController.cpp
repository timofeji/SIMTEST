// Fill out your copyright notice in the Description page of Project Settings.


#include "SIMPlayerController.h"



#include "EngineUtils.h"
#include "SIMGRID.h"
#include "SIMGridSquare.h"
#include "SquareActors/WolfActor.h"


ASIMPlayerController::ASIMPlayerController()
{
	SimState = ESIMState::RABBIT;
}

void ASIMPlayerController::BeginPlay()
{
	FVector Location = FVector(-1950.0f, -1880.0f, 0.f);
	FRotator Rotation(0.0f, 0.0f, 180.0f);
	FActorSpawnParameters SpawnInfo;
	GridActor = GetWorld()->SpawnActor<ASIMGRID>(SIMGRIDActor, Location, Rotation, SpawnInfo);
}

void ASIMPlayerController::PlaceSimActor(FSIMPosID Id)
{
	if (SimState == ESIMState::RUNNING)
		return;

	check(SimState != ESIMState::RUNNING)

	if(SimState == ESIMState::RABBIT)
	{
		FVector Location = GridActor->GetGridLocByID(Id);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		ASIMGridActor* Rabbit = GetWorld()->SpawnActor<ASIMGridActor>(RabbitActor, Location, Rotation, SpawnInfo);

		if (Rabbit)
		{
			Rabbit->SetPosID(Id);
			SimState = ESIMState::WOLF;
			GridActor->SIMPlaceActor(Rabbit);
			RRef = Rabbit;
		}
	}
	else if (SimState == ESIMState::WOLF)
	{
		FVector Location = GridActor->GetGridLocByID(Id);
		FRotator Rotation(0.0f, 0.0f, 0.0f);
		FActorSpawnParameters SpawnInfo;
		ASIMGridActor* Wolf = GetWorld()->SpawnActor<ASIMGridActor>(WolfActor, Location, Rotation, SpawnInfo);

		if (Wolf)
		{
			Wolf->SetPosID(Id);
			GridActor->SIMPlaceActor(Wolf);

			if(auto W{Cast<AWolfActor>(Wolf)})
			{
				W->SetRabbitRef(RRef);
			}
			GridActor->SIMStart();
			SimState = ESIMState::RUNNING;
		}
	}
}
