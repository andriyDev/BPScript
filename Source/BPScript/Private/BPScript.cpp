// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "BPScript.h"

IMPLEMENT_GAME_MODULE(FBPScriptModule, BPScript);

DEFINE_LOG_CATEGORY(BPScript)

#define LOCTEXT_NAMESPACE "BPScript"

void FBPScriptModule::StartupModule()
{
	
}

void FBPScriptModule::ShutdownModule()
{
	
}

#undef LOCTEXT_NAMESPACE