
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "BPScriptCommandlet.h"
#include "Engine/Blueprint.h"
#include "AssetRegistryModule.h"
#include "Factories/BlueprintFactory.h"
#include "Editor/UnrealEd/Public/FeedbackContextEditor.h"

#include "BPScriptTokenizer.h"

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

	// Setup a read buffer
	char buf[TOKENIZER_BUFFER_SIZE];
	int buf_size = 0;
	int start_pos = 0;
	buf[0] = '\0';

	// Open the script file. This file will be used to tokenize the script
	std::FILE* token_file;
	if (fopen_s(&token_file, TCHAR_TO_UTF8(*Tokens[0]), "rb") != 0)
	{
		UE_LOG(BPScript, Display, TEXT("Could not open script file!"));
		return 1;
	}
	// Open the script file. This file will be used to read the tokens
	std::FILE* read_file;
	if (fopen_s(&read_file, TCHAR_TO_UTF8(*Tokens[0]), "rb") != 0)
	{
		UE_LOG(BPScript, Display, TEXT("Could not open script file!"));
		return 1;
	}

	// Setup a mapping from enum to strings
	FString enumToTokens[] = { "Whitespace", "Identifier", "Keyword", "Symbol", "Number", "Comment", "String" };

	// Keep tokenizing until there is no token.
	struct Token* tok;
	while ((tok = ReadTokenFromBounds(Tokenize(buf, buf_size, start_pos, token_file), read_file)) != nullptr)
	{
		UE_LOG(BPScript, Display, TEXT("Token Type: %s\t\"%s\""), *enumToTokens[(int)tok->type], *FString(tok->val.c_str()));
		delete tok;
	}

	return 0;
}
