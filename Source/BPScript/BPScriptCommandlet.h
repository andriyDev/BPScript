
#pragma once

#include "BPScript.h"

#include "Commandlets/Commandlet.h"
#include "Logging/LogMacros.h"

#include "BPScriptCommandlet.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCommandletPlugin, Log, All);

UCLASS()
class UBPScriptCommandlet : public UCommandlet
{
	GENERATED_BODY()
public:
	UBPScriptCommandlet();

	virtual int32 Main(const FString& Params) override;
};