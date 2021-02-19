// Fill out your copyright notice in the Description page of Project Settings.


#include "SIMGridActor.h"


#include "SIMPlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASIMGridActor::ASIMGridActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxMoves = 1;

}

// Called when the game starts or when spawned
void ASIMGridActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASIMGridActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Inefficient but pretty
	SetActorLocation(FMath::VInterpTo(GetActorLocation(), SIMGRID->GetGridLocByID(SIMID),  DeltaTime, 4.f));
}

void ASIMGridActor::SetPosID(FSIMPosID Id)
{
	SIMID = Id;
}

FSIMPosID ASIMGridActor::Move(uint32 iter)
{
	FSIMPosID ID;
	ID.PosX = MaxMoves % (iter + 1);
	ID.PosY = MaxMoves + 1 % (iter + 1);
	return ID;
}

void ASIMGridActor::InitSquare(ASIMGRID* Asimgrid)
{
	SIMGRID = Asimgrid;
}

void ASIMGridActor::UpdateSIM(uint32 iter)
{
	SIMID = Move(iter);
}

