// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SIMTypes.h"
#include "GameFramework/Actor.h"
#include "SIMGridSquare.generated.h"

UCLASS()
class SIM_API ASIMGridSquare : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASIMGridSquare();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintCallable)
	void Clicked();

	//Sets position ID
	void SetID(int I, int J);


private:
	FSIMPosID SIMID;
};
