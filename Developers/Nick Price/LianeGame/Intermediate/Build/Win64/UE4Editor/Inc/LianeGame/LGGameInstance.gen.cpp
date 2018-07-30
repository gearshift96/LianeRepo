// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "LGGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLGGameInstance() {}
// Cross Module References
	LIANEGAME_API UScriptStruct* Z_Construct_UScriptStruct_FSoundResult();
	UPackage* Z_Construct_UPackage__Script_LianeGame();
	ENGINE_API UClass* Z_Construct_UClass_USoundWave_NoRegister();
	LIANEGAME_API UClass* Z_Construct_UClass_ULGGameInstance_NoRegister();
	LIANEGAME_API UClass* Z_Construct_UClass_ULGGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	LIANEGAME_API UFunction* Z_Construct_UFunction_ULGGameInstance_AddToSoundWaveList();
	LIANEGAME_API UFunction* Z_Construct_UFunction_ULGGameInstance_GetSoundWaveFromList();
// End Cross Module References
class UScriptStruct* FSoundResult::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern LIANEGAME_API uint32 Get_Z_Construct_UScriptStruct_FSoundResult_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSoundResult, Z_Construct_UPackage__Script_LianeGame(), TEXT("SoundResult"), sizeof(FSoundResult), Get_Z_Construct_UScriptStruct_FSoundResult_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSoundResult(FSoundResult::StaticStruct, TEXT("/Script/LianeGame"), TEXT("SoundResult"), false, nullptr, nullptr);
static struct FScriptStruct_LianeGame_StaticRegisterNativesFSoundResult
{
	FScriptStruct_LianeGame_StaticRegisterNativesFSoundResult()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SoundResult")),new UScriptStruct::TCppStructOps<FSoundResult>);
	}
} ScriptStruct_LianeGame_StaticRegisterNativesFSoundResult;
	UScriptStruct* Z_Construct_UScriptStruct_FSoundResult()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSoundResult_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_LianeGame();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SoundResult"), sizeof(FSoundResult), Get_Z_Construct_UScriptStruct_FSoundResult_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "LGGameInstance.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSoundResult>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoundWave_MetaData[] = {
				{ "ModuleRelativePath", "LGGameInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SoundWave = { UE4CodeGen_Private::EPropertyClass::Object, "SoundWave", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, STRUCT_OFFSET(FSoundResult, SoundWave), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(NewProp_SoundWave_MetaData, ARRAY_COUNT(NewProp_SoundWave_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bNew_MetaData[] = {
				{ "ModuleRelativePath", "LGGameInstance.h" },
			};
#endif
			auto NewProp_bNew_SetBit = [](void* Obj){ ((FSoundResult*)Obj)->bNew = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bNew = { UE4CodeGen_Private::EPropertyClass::Bool, "bNew", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FSoundResult), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bNew_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bNew_MetaData, ARRAY_COUNT(NewProp_bNew_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
				{ "ModuleRelativePath", "LGGameInstance.h" },
			};
#endif
			auto NewProp_bSuccess_SetBit = [](void* Obj){ ((FSoundResult*)Obj)->bSuccess = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSuccess = { UE4CodeGen_Private::EPropertyClass::Bool, "bSuccess", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000000, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FSoundResult), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bSuccess_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bSuccess_MetaData, ARRAY_COUNT(NewProp_bSuccess_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SoundWave,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bNew,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bSuccess,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_LianeGame,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"SoundResult",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FSoundResult),
				alignof(FSoundResult),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSoundResult_CRC() { return 3839775681U; }
	void ULGGameInstance::StaticRegisterNativesULGGameInstance()
	{
		UClass* Class = ULGGameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddToSoundWaveList", &ULGGameInstance::execAddToSoundWaveList },
			{ "GetSoundWaveFromList", &ULGGameInstance::execGetSoundWaveFromList },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ULGGameInstance_AddToSoundWaveList()
	{
		struct LGGameInstance_eventAddToSoundWaveList_Parms
		{
			TSoftObjectPtr<USoundWave> SoundWaveAsset;
			FSoundResult ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LGGameInstance_eventAddToSoundWaveList_Parms, ReturnValue), Z_Construct_UScriptStruct_FSoundResult, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_SoundWaveAsset = { UE4CodeGen_Private::EPropertyClass::SoftObject, "SoundWaveAsset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(LGGameInstance_eventAddToSoundWaveList_Parms, SoundWaveAsset), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SoundWaveAsset,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "C++Function" },
				{ "ModuleRelativePath", "LGGameInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULGGameInstance, "AddToSoundWaveList", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LGGameInstance_eventAddToSoundWaveList_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ULGGameInstance_GetSoundWaveFromList()
	{
		struct LGGameInstance_eventGetSoundWaveFromList_Parms
		{
			TSoftObjectPtr<USoundWave> SoundWaveAsset;
			FSoundResult ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(LGGameInstance_eventGetSoundWaveFromList_Parms, ReturnValue), Z_Construct_UScriptStruct_FSoundResult, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FSoftObjectPropertyParams NewProp_SoundWaveAsset = { UE4CodeGen_Private::EPropertyClass::SoftObject, "SoundWaveAsset", RF_Public|RF_Transient|RF_MarkAsNative, 0x0014000000000080, 1, nullptr, STRUCT_OFFSET(LGGameInstance_eventGetSoundWaveFromList_Parms, SoundWaveAsset), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SoundWaveAsset,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "C++Function" },
				{ "ModuleRelativePath", "LGGameInstance.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ULGGameInstance, "GetSoundWaveFromList", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(LGGameInstance_eventGetSoundWaveFromList_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ULGGameInstance_NoRegister()
	{
		return ULGGameInstance::StaticClass();
	}
	UClass* Z_Construct_UClass_ULGGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UGameInstance,
				(UObject* (*)())Z_Construct_UPackage__Script_LianeGame,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ULGGameInstance_AddToSoundWaveList, "AddToSoundWaveList" }, // 2853163919
				{ &Z_Construct_UFunction_ULGGameInstance_GetSoundWaveFromList, "GetSoundWaveFromList" }, // 707806253
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "LGGameInstance.h" },
				{ "ModuleRelativePath", "LGGameInstance.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ULGGameInstance>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ULGGameInstance::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100088u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULGGameInstance, 1250405853);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULGGameInstance(Z_Construct_UClass_ULGGameInstance, &ULGGameInstance::StaticClass, TEXT("/Script/LianeGame"), TEXT("ULGGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULGGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
