// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test2MP/Public/Interactable.h"
#include "Door.generated.h"

class UAnimationAsset;

UCLASS()
class TEST2MP_API ADoor : public AInteractable
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void OnRep_Interact() override;

public:
	virtual void Interact() override;
};
