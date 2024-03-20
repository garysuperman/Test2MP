// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS(ABSTRACT)
class TEST2MP_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	AInteractable();

protected:

	UPROPERTY(EditAnywhere, Category = "Test2")
	class USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = "Test2")
	UAnimationAsset* OnAnim;
	UPROPERTY(EditAnywhere, Category = "Test2")
	UAnimationAsset* OffAnim;

	UPROPERTY(ReplicatedUsing = OnRep_Interact)
	bool Toggled;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override {};

	UFUNCTION()
	virtual void OnRep_Interact() {};

public:
	virtual void Interact() {};
};
