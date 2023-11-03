// Shoot Them Up Game. 

using UnrealBuildTool;
using System.Collections.Generic;

public class STUGameTarget : TargetRules
{
	public STUGameTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "STUGame" } );
	}
}
