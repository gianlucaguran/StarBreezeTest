// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class StarbreezeFPSTestEditorTarget : TargetRules
{
	public StarbreezeFPSTestEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("StarbreezeFPSTest");
	}
}
