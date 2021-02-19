// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SIM/SIMGridActor.h"
#include "RabbitActor.generated.h"

/**
 * 
 */
UCLASS()
class SIM_API ARabbitActor : public ASIMGridActor
{
	GENERATED_BODY()

	virtual FSIMPosID Move(uint32 iter) override;
	
};
