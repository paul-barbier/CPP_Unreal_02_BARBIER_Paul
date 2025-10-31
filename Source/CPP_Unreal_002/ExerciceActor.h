// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExerciceActor.generated.h"

UCLASS()
class CPP_UNREAL_002_API AExerciceActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AExerciceActor();

	UFUNCTION(BlueprintCallable)
	void OnConstruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Visual")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditInstanceOnly, meta = (AllowPrivateAccess = "true"), Category = "Visual")
	bool SwitchComponent;

	USceneComponent* Root;
	UStaticMesh* SphereMesh;
	UStaticMesh* CubeMesh;
};
