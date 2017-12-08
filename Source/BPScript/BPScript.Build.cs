// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
using System.IO;
using UnrealBuildTool;

namespace UnrealBuildTool.Rules
{
	public class BPScript : ModuleRules
	{
		public BPScript(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {

				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine",
					"InputCore",
					"SlateCore",
					// ... add other public dependencies that you statically link with here ...
				}
				);

			if (Target.bBuildEditor == true)
			{

				PublicDependencyModuleNames.AddRange(
					new string[] 
					{
						"UnrealEd", 
					}
				);

			}


			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);
		}
	}
}
