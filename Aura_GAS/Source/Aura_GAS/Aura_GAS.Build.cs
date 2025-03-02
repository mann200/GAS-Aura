// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Aura_GAS : ModuleRules
{
	public Aura_GAS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","EnhancedInput","GameplayAbilities"});

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags","GameplayTasks","NavigationSystem","Niagara","AIModule" });
		
	}
}
