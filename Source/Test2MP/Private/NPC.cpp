// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2MP/Public/NPC.h"

// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();

	//Play Idle anim
	Toggled = false;
	if(OffAnim)
		Mesh->PlayAnimation(OffAnim, true);
}

void ANPC::Interact()
{
	if (Toggled)
	{
		Toggled = false;
		if (OffAnim)
		{
			Mesh->PlayAnimation(OffAnim, true);
		}
	}
	else
	{
		Toggled = true;
		if (OnAnim)
		{
			Mesh->PlayAnimation(OnAnim, true);
		}
	}
	
}
