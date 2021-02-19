// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SIMGRID.h"
#include "GameFramework/Actor.h"
#include "SIMTypes.h"
#include "SIMGridActor.generated.h"

UCLASS()
class SIM_API ASIMGridActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASIMGridActor();


	UPROPERTY(EditAnywhere)
		uint32 MaxMoves;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Sets position ID
	void SetPosID(FSIMPosID Id);

	virtual FSIMPosID Move(uint32 iter);
	
	void InitSquare(ASIMGRID* Asimgrid);
	void UpdateSIM(uint32 iter);


	ASIMGRID* SIMGRID;
	FSIMPosID SIMID;
};
