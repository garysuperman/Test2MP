// Copyright Epic Games, Inc. All Rights Reserved.

#include "Test2MPGameMode.h"
#include "Test2MPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATest2MPGameMode::ATest2MPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
