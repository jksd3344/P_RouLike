// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class P_RouLike : ModuleRules
{
	public P_RouLike(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		OptimizeCode = CodeOptimization.Never;
        PublicDependencyModuleNames.AddRange(new string[]
        {
	        "Core",
	        "CoreUObject",
	        "Engine", 
	        "InputCore", 
	        "UMG", 
	        "AIModule",
	        "GameplayAbilities",
	        "GameplayTags",
	        "GameplayTasks",
        });
    }
}
