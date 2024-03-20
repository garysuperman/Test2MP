// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2MP/Public/NPC.h"
#include <Net/UnrealNetwork.h>

// Sets default values
ANPC::ANPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	RootComponent = Mesh;

	bReplicates = true;

	Toggled = true;
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();

	//Play Idle anim
	
	if(OffAnim)
		Mesh->PlayAnimation(OffAnim, true);
}

void ANPC::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANPC, Toggled);
}

void ANPC::OnRep_Interact()
{
	if (Toggled)
	{
		if (OffAnim)
		{
			Mesh->PlayAnimation(OffAnim, true);
		}
	}
	else
	{
		if (OnAnim)
		{
			Mesh->PlayAnimation(OnAnim, true);
		}
	}
}

void ANPC::Interact()
{
	if (HasAuthority())
	{
		Toggled = !Toggled;
		OnRep_Interact();
	}

}