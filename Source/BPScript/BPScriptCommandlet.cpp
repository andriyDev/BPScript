
#include "BPScript.h"

#include "BPScriptCommandlet.h"
#include "Engine/Blueprint.h"
#include "AssetRegistryModule.h"
#include "Factories/BlueprintFactory.h"
#include "Editor/UnrealEd/Public/FeedbackContextEditor.h"

DEFINE_LOG_CATEGORY(LogCommandletPlugin);

UBPScriptCommandlet::UBPScriptCommandlet()
{
	IsClient = false;
	IsEditor = false;
	IsServer = false;
	LogToConsole = true;
}



int32 UBPScriptCommandlet::Main(const FString& Params)
{
	FString AssetPath = TEXT("../../../GameWorkspace/Content/");
	FString PackageName = TEXT("/Game/TestAsset");
	UPackage* Package = CreatePackage(NULL, *PackageName);

	FFeedbackContextEditor ffce;

	UBlueprintFactory* Factory = NewObject<UBlueprintFactory>();
	Factory->ParentClass = AActor::StaticClass();
	AActor* NewAsset = Cast<AActor>(Factory->FactoryCreateNew(UBlueprint::StaticClass(), Package, *FString("TestAsset"), EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, nullptr, &ffce));
	
	if (NewAsset != NULL)
	{
		// Fill in the assets data here
	}

	FAssetRegistryModule::AssetCreated(NewAsset);
	NewAsset->MarkPackageDirty();
	FString FilePath = FString::Printf(TEXT("%s%s%s"), *AssetPath, *FString("TestAsset"), *FPackageName::GetAssetPackageExtension());
	bool bSuccess = UPackage::SavePackage(Package, NewAsset, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *FilePath);

	return 0;
}
