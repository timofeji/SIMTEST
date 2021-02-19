// Fill out your copyright notice in the Description page of Project Settings.


#include "SIMGRID.h"


#include "SIMGridActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASIMGRID::ASIMGRID()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SquareSpacing = 200.f;
	SimStepTime = 0.4f;
	SimIter = 0;

	bIsSIMRunning = false;

}

// Called when the game starts or when spawned
void ASIMGRID::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{

			FVector Location(i * SquareSpacing, j * SquareSpacing, 0.0f);
			Location += GetActorLocation();
			FRotator Rotation(0.0f, 0.0f, 0.0f);
			FActorSpawnParameters SpawnInfo;
			ASIMGridSquare * Square = GetWorld()->SpawnActor<ASIMGridSquare>(GridSquareActor, Location, Rotation, SpawnInfo);
			Square->SetID(i,j);
		}
	}
}
void ASIMGRID::SIMStep()
{

	if(bIsSIMRunning)
	{
		
		SimIter++;
		
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, SimStepTime, FColor::Yellow, FString::FromInt(SimIter));
		
		for (ASIMGridActor* Actor : SIMActors)
		{
			Actor->UpdateSIM(SimIter);
		}

	} else
	{
		GetWorld()->GetTimerManager().ClearTimer(SIMTimerHandle);
	}
}

void ASIMGRID::SIMStart()
{
	GetWorld()->GetTimerManager().SetTimer(SIMTimerHandle, this, &ASIMGRID::SIMStep, SimStepTime, true);
	bIsSIMRunning = true;
}

void ASIMGRID::SIMBreak()
{

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, SimStepTime, FColor::Yellow, "Simulation ENDED");
	bIsSIMRunning = false;
}

void ASIMGRID::SIMPlaceActor(ASIMGridActor* Actor)
{
	SIMActors.Add(Actor);

	//Just keep a reference to this grid actor
	Actor->InitSquare(this);
}


FVector ASIMGRID::GetGridLocByID(FSIMPosID Id) const
{
	return FVector(Id.PosX * SquareSpacing, Id.PosY * SquareSpacing, 0.0f) + GetActorLocation();
}


ASIMGridSquare* ASIMGRID::GetGridSquareByID(FSIMPosID Id)
{
	return GridSquareArr[Id.PosX][Id.PosY];
}

