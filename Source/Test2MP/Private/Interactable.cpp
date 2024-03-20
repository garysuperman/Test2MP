// Fill out your copyright notice in the Description page of Project Settings.


#include "Test2MP/Public/Interactable.h"
#include <Net/UnrealNetwork.h>

// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void AInteractable::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AInteractable, Toggled);
}

void AInteractable::OnRep_Interact(){}

void AInteractable::Interact() {}

