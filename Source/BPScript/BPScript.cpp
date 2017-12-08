#include "BPScript.h"
#include "Modules/ModuleManager.h"
#include "Modules/ModuleInterface.h"
 
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