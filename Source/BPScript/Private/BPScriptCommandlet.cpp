
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BPScriptCommandlet.h"
#include "Engine/Blueprint.h"
#include "AssetRegistryModule.h"
#include "Factories/BlueprintFactory.h"
#include "Editor/UnrealEd/Public/FeedbackContextEditor.h"

#include "BPScriptParser.h"

#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

UBPScriptCommandlet::UBPScriptCommandlet()
{
	IsClient = false;
	IsEditor = false;
	IsServer = false;
	LogToConsole = true;
}

void CreateBlueprintAsset()
{
	// Create the package
	FString AssetPath = FPaths::ProjectContentDir();
	FString PackageName = TEXT("/Game/TestAsset");
	UPackage* Package = CreatePackage(NULL, *PackageName);

	FFeedbackContextEditor ffce;

	UBlueprintFactory* Factory = NewObject<UBlueprintFactory>();
	Factory->ParentClass = AActor::StaticClass();
	UBlueprint* NewAsset = Cast<UBlueprint>(Factory->FactoryCreateNew(UBlueprint::StaticClass(), Package, *FString("TestAsset"), EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, nullptr, &ffce));

	if (NewAsset != NULL)
	{
		// Fill in the assets data here
		UE_LOG(BPScript, Display, TEXT("Blueprint is valid!"));
	}
	else
	{
		UE_LOG(BPScript, Display, TEXT("Blueprint is not valid!"));
	}

	FAssetRegistryModule::AssetCreated(NewAsset);
	NewAsset->MarkPackageDirty();
	FString FilePath = FString::Printf(TEXT("%s%s%s"), *AssetPath, *FString("TestAsset"), *FPackageName::GetAssetPackageExtension());
	UPackage::SavePackage(Package, NewAsset, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *FilePath);
}

int32 UBPScriptCommandlet::Main(const FString& Params)
{
	// Tokenize the parameters
	TArray<FString> Tokens;
	TArray<FString> Switches;
	TMap<FString, FString> SwitchParams;
	ParseCommandLine(*Params, Tokens, Switches, SwitchParams);
	for (FString str : Tokens)
	{
		UE_LOG(BPScript, Display, TEXT("%s"), *str);
	}

	//IKismetCompilerInterface* KismetBlueprintCompilerModule = &FModuleManager::LoadModuleChecked<IKismetCompilerInterface>(TEXT(KISMET_COMPILER_MODULENAME));
	
	BPScriptParser Parser;
	
	if (Parser.ReadScript(TCHAR_TO_UTF8(*Tokens[0])) != 0)
	{
		return 1;
	}

	return 0;
}
