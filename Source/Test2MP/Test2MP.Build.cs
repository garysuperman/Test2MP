// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Test2MP : ModuleRules
{
	public Test2MP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
