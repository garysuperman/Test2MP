// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2MP/Public/Switch.h"
#include <Net/UnrealNetwork.h>

// Sets default values
ASwitch::ASwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;

	bReplicates = true;

	Toggled = true;
}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();

	if (OffAnim)
		Mesh->PlayAnimation(OffAnim, false);
	
}

void ASwitch::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASwitch, Toggled);
}

void ASwitch::OnRep_Interact()
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

void ASwitch::Interact()
{
	if (HasAuthority())
	{
		Toggled = !Toggled;
		OnRep_Interact();
	}

}
