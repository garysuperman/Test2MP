// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

class UAnimationAsset;

UCLASS()
class TEST2MP_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	UPROPERTY(EditAnywhere, Category = "Test2")
	class USkeletalMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere, Category = "Test2")
	UAnimationAsset* OpenAnimation;
	UPROPERTY(EditAnywhere, Category = "Test2")
	UAnimationAsset* CloseAnimation;

	bool bDoorOpen;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void ToggleDoor();
};
