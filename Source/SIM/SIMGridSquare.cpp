// Fill out your copyright notice in the Description page of Project Settings.


#include "SIMGridSquare.h"


#include "SIMPlayerController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ASIMGridSquare::ASIMGridSquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASIMGridSquare::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASIMGridSquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASIMGridSquare::Clicked()
{
	if (auto SIMCtrl{ Cast< ASIMPlayerController>(GetWorld()->GetFirstPlayerController()) })
	{
		SIMCtrl->PlaceSimActor(SIMID);
	}
}

void ASIMGridSquare::SetID(int I, int J)
{
	SIMID.PosX = I;
	SIMID.PosY = J;
}

