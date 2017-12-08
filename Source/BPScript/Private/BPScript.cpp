// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "BPScript.h"

IMPLEMENT_GAME_MODULE(FBPScriptModule, BPScript);

DEFINE_LOG_CATEGORY(BPScript)

#define LOCTEXT_NAMESPACE "BPScript"

void FBPScriptModule::StartupModule()
{
	UE_LOG(BPScript, Warning, TEXT("BPScript: Log Started"));
}

void FBPScriptModule::ShutdownModule()
{
	UE_LOG(BPScript, Warning, TEXT("BPScript: Log Ended"));
}

#undef LOCTEXT_NAMESPACE