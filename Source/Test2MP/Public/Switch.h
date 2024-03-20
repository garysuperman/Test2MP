// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Test2MP/Public/Interactable.h"
#include "Switch.generated.h"

UCLASS()
class TEST2MP_API ASwitch : public AInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitch();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void Interact() override;
};
