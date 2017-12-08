
#pragma once

#include "CoreMinimal.h"

#include "BPScript.h"
#include "Commandlets/Commandlet.h"
#include "Logging/LogMacros.h"

#include "BPScriptCommandlet.generated.h"

UCLASS()
class UBPScriptCommandlet : public UCommandlet
{
	GENERATED_BODY()
public:
	UBPScriptCommandlet();

	virtual int32 Main(const FString& Params) override;
};