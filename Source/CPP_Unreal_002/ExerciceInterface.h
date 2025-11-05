// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ExerciceInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UExerciceInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CPP_UNREAL_002_API IExerciceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetLocation(const FVector& Location);
};
