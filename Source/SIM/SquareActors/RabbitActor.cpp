// Fill out your copyright notice in the Description page of Project Settings.


#include "RabbitActor.h"

FSIMPosID ARabbitActor::Move(uint32 iter)
{


	//Deterministic Pseudorandom move
	FSIMPosID ID = SIMID;

	if (iter % 2 == 0)
	{
		ID.PosX += 1 * (iter % 7 == 0);
		ID.PosY += 1 * (iter % 2 == 0);
	} else
	{
		ID.PosX -= 1 * (iter % 3 == 0);
		ID.PosY -= 1 * (iter % 2 == 0);
	}

	

	// check for bounds
	if (ID.PosY <= 0 || ID.PosY >= 19 || ID.PosX <= 0 || ID.PosX >= 19)
	{
		SIMGRID->SIMBreak();
	}
	return ID;
}
