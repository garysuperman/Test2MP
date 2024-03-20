// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2MP/Public/Switch.h"

// Sets default values
ASwitch::ASwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;

	Toggled = false;
}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();

	if (OffAnim)
	{
		Mesh->PlayAnimation(OffAnim, false);
	}
}

void ASwitch::Interact()
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

