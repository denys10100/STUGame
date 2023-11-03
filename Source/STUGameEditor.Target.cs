// Shoot Them Up Game. 

using UnrealBuildTool;
using System.Collections.Generic;

public class STUGameEditorTarget : TargetRules
{
	public STUGameEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "STUGame" } );
	}
}
