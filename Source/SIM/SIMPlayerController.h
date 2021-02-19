// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SIMGRID.h"
#include "GameFramework/PlayerController.h"
#include "SIMTypes.h"
#include "SIMGridActor.h"
#include "SIMPlayerController.generated.h"


UENUM(BlueprintType)
enum class ESIMState : uint8
{
	RABBIT,
	WOLF,
	RUNNING
};

/**
 * 
 */
UCLASS()
class SIM_API ASIMPlayerController : public APlayerController
{
	GENERATED_BODY()

	ASIMPlayerController();

public:


	virtual void BeginPlay() override;
	
	void PlaceSimActor(FSIMPosID Id);

	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASIMGridActor> RabbitActor;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASIMGridActor> WolfActor;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASIMGRID> SIMGRIDActor;
	
	ASIMGRID* GridActor;

protected:
	ESIMState SimState;


	//Keep temporary rabbit reference to set for wolf
	ASIMGridActor* RRef;

};
