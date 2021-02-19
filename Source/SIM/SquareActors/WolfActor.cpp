// Fill out your copyright notice in the Description page of Project Settings.


#include "WolfActor.h"

FSIMPosID AWolfActor::Move(uint32 iter)
{

	FSIMPosID ID = SIMID;
	if (RabbitRef)
	{
		FSIMPosID RabbitID = RabbitRef->SIMID;

		int distX = (RabbitID.PosX - ID.PosX);
		int distY = (RabbitID.PosY - ID.PosY);

		if (distX > 0 || distY > 0)
		{
			ID.PosX += (distY < distX) ? 2 : 0;
			ID.PosY += (distX < distY) ? 2 : 0;
		} else
		{
			ID.PosX -= (distY < distX) ? 2 : 0;
			ID.PosY -= (distX < distY) ? 2 : 0;
		}


		//Break if wolf caught rabbit
		if(FMath::Sqrt(FMath::Square(distX) + FMath::Square(distY)) <= 1)
		{
			SIMGRID->SIMBreak();
		}

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, FString::FromInt(distX));
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, FString::FromInt(distY));
		}
	} else // move random
	{
		ID.PosX = SIMID.PosX;
		ID.PosY = SIMID.PosY + 1;
	}
	return ID;
}

void AWolfActor::SetRabbitRef(ASIMGridActor* Rabbit)
{
	RabbitRef = Rabbit;
}
