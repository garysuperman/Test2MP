// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2MP/Public/Door.h"
#include "Components/SkeletalMeshComponent.h"
#include <Net/UnrealNetwork.h>

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;

	bReplicates = true;

	Toggled = true;
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
}

void ADoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADoor, Toggled);
}

void ADoor::OnRep_Interact()
{
	if (Toggled)
	{
		if (OffAnim) 
		{
			Mesh->PlayAnimation(OffAnim, false);
		}
	}
	else
	{
		
		if (OnAnim)
		{
			Mesh->PlayAnimation(OnAnim, false);
		}
	}
}

void ADoor::Interact()
{
	if(HasAuthority())
	{
		Toggled = !Toggled;
		OnRep_Interact();
	}
	
}

