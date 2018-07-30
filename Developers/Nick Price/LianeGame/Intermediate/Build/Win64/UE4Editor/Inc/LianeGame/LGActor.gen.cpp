// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "LGActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLGActor() {}
// Cross Module References
	LIANEGAME_API UClass* Z_Construct_UClass_ALGActor_NoRegister();
	LIANEGAME_API UClass* Z_Construct_UClass_ALGActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LianeGame();
	ENGINE_API UClass* Z_Construct_UClass_USoundWave_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ALGActor::StaticRegisterNativesALGActor()
	{
	}
	UClass* Z_Construct_UClass_ALGActor_NoRegister()
	{
		return ALGActor::StaticClass();
	}
	UClass* Z_Construct_UClass_ALGActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_LianeGame,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "LGActor.h" },
				{ "ModuleRelativePath", "LGActor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireAndForgetSoundAssetList_MetaData[] = {
				{ "Category", "C++Property" },
				{ "ModuleRelativePath", "LGActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_FireAndForgetSoundAssetList = { UE4CodeGen_Private::EPropertyClass::Map, "FireAndForgetSoundAssetList", RF_Public|RF_Transient|RF_MarkAsNative, 0x0024080000000005, 1, nullptr, STRUCT_OFFSET(ALGActor, FireAndForgetSoundAssetList), METADATA_PARAMS(NewProp_FireAndForgetSoundAssetList_MetaData, ARRAY_COUNT(NewProp_FireAndForgetSoundAssetList_MetaData)) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_FireAndForgetSoundAssetList_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Name, "FireAndForgetSoundAssetList_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_FireAndForgetSoundAssetList_ValueProp = { UE4CodeGen_Private::EPropertyClass::SoftObject, "FireAndForgetSoundAssetList", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000001, 1, nullptr, 1, Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundComponentAssetList_MetaData[] = {
				{ "Category", "C++Property" },
				{ "ModuleRelativePath", "LGActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FMapPropertyParams NewProp_SoundComponentAssetList = { UE4CodeGen_Private::EPropertyClass::Map, "SoundComponentAssetList", RF_Public|RF_Transient|RF_MarkAsNative, 0x0024080000000005, 1, nullptr, STRUCT_OFFSET(ALGActor, SoundComponentAssetList), METADATA_PARAMS(NewProp_SoundComponentAssetList_MetaData, ARRAY_COUNT(NewProp_SoundComponentAssetList_MetaData)) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_SoundComponentAssetList_Key_KeyProp = { UE4CodeGen_Private::EPropertyClass::Name, "SoundComponentAssetList_Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000001, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_SoundComponentAssetList_ValueProp = { UE4CodeGen_Private::EPropertyClass::SoftObject, "SoundComponentAssetList", RF_Public|RF_Transient|RF_MarkAsNative, 0x0004000000000001, 1, nullptr, 1, Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StaticMeshComponent_MetaData[] = {
				{ "Category", "C++Property" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "LGActor.h" },
				{ "ToolTip", "UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = \"Box component\")\nUBoxComponent* BoxComponent;" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StaticMeshComponent = { UE4CodeGen_Private::EPropertyClass::Object, "StaticMeshComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x001000000008000d, 1, nullptr, STRUCT_OFFSET(ALGActor, StaticMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_StaticMeshComponent_MetaData, ARRAY_COUNT(NewProp_StaticMeshComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FireAndForgetSoundAssetList,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FireAndForgetSoundAssetList_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FireAndForgetSoundAssetList_ValueProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SoundComponentAssetList,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SoundComponentAssetList_Key_KeyProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SoundComponentAssetList_ValueProp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_StaticMeshComponent,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ALGActor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ALGActor::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALGActor, 1923173887);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALGActor(Z_Construct_UClass_ALGActor, &ALGActor::StaticClass, TEXT("/Script/LianeGame"), TEXT("ALGActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALGActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
