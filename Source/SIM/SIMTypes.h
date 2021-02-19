#pragma once

#include "CoreMinimal.h"
#include "SIMTypes.generated.h"

USTRUCT(BlueprintType)
struct  SIM_API FSIMPosID
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	uint32 PosX = 0;
	
	UPROPERTY(EditDefaultsOnly)
	uint32 PosY = 0;
};
