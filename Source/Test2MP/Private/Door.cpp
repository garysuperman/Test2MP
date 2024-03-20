// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2MP/Public/Door.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;

	Toggled = false;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
}

void ADoor::Interact()
{
	if (Toggled)
	{
		Toggled = false;
		if (OffAnim) 
		{
			Mesh->PlayAnimation(OffAnim, false);
		}
	}
	else
	{
		Toggled = true;
		if (OnAnim)
		{
			Mesh->PlayAnimation(OnAnim, false);
		}
	}
}

