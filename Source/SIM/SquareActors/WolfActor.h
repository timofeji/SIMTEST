// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SIM/SIMGridActor.h"
#include "WolfActor.generated.h"

/**
 * 
 */
UCLASS()
class SIM_API AWolfActor : public ASIMGridActor
{
	GENERATED_BODY()
public:
	virtual FSIMPosID Move(uint32 iter) override;


	void SetRabbitRef(ASIMGridActor* Rabbit);

protected:
	ASIMGridActor* RabbitRef;
	
};
