// Fill out your copyright notice in the Description page of Project Settings.


#include "ExerciceActor.h"

// Sets default values
AExerciceActor::AExerciceActor()
{
	PrimaryActorTick.bCanEverTick = true;

	//Création de la racine de l'objet 
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	//On créer le static Mesh et on l'attache à la racine 
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComponent->SetupAttachment(Root);

	SwitchComponent = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeMeshFinder(TEXT("/Engine/EditorMeshes/EditorCube.EditorCube"));
	if (cubeMeshFinder.Succeeded())
		MeshComponent->SetStaticMesh(cubeMeshFinder.Object);
	CubeMesh = cubeMeshFinder.Object;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> sphereMeshFinder(TEXT("/Engine/EditorMeshes/EditorSphere.EditorSphere"));
	if (sphereMeshFinder.Succeeded())
		MeshComponent->SetStaticMesh(sphereMeshFinder.Object);
	SphereMesh = sphereMeshFinder.Object;
}

void AExerciceActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (SwitchComponent)
		MeshComponent->SetStaticMesh(SphereMesh);
	else
		MeshComponent->SetStaticMesh(CubeMesh);
}

// Called when the game starts or when spawned
void AExerciceActor::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->SetStaticMesh(CubeMesh);
}

// Called every frame
void AExerciceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OnConstruction(GetActorTransform());
}





