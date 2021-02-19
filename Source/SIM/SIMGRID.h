// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SIMGridSquare.h"
#include "GameFramework/Actor.h"
#include "SIMTypes.h"
#include "SIMGRID.generated.h"


class ASIMGridActor;

UCLASS()
class SIM_API ASIMGRID : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASIMGRID();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	
	//Called on each time step of simulation
	virtual void SIMStep();

	//Starts the simulation after all pieces placed
	virtual void SIMStart();
	
	//Starts the simulation after all pieces placed
	virtual void SIMBreak();
	
	virtual void SIMPlaceActor(ASIMGridActor* Actor );
	
	FVector GetGridLocByID(FSIMPosID Id) const;

	//Time between sim steps
	UPROPERTY(EditDefaultsOnly)
	float SimStepTime;

	UPROPERTY(EditDefaultsOnly)
	float SquareSpacing;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASIMGridSquare> GridSquareActor;

	UFUNCTION(BlueprintCallable)
	ASIMGridSquare* GetGridSquareByID(FSIMPosID Id);

protected:
	TArray<TArray<ASIMGridSquare*>> GridSquareArr;

	TArray<ASIMGridActor*> SIMActors;
	
	bool bIsSIMRunning;

	uint32 SimIter;

	FTimerHandle SIMTimerHandle;

};
