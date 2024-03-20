// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2MP/Public/Door.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DoorMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = DoorMesh;

	bDoorOpen = false;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoor::ToggleDoor()
{
	if (bDoorOpen)
	{
		bDoorOpen = false;
		if (CloseAnimation) 
		{
			DoorMesh->PlayAnimation(CloseAnimation, false);
		}
	}
	else
	{
		bDoorOpen = true;
		if (OpenAnimation)
		{
			DoorMesh->PlayAnimation(OpenAnimation, false);
		}
	}
}

