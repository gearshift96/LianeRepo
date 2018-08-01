// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLianeGame_init() {}
	LIANEGAME_API UFunction* Z_Construct_UDelegateFunction_LianeGame_OnHealthChangedSignature__DelegateSignature();
	LIANEGAME_API UFunction* Z_Construct_UDelegateFunction_LianeGame_OnActorKilled__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_LianeGame()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_LianeGame_OnHealthChangedSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_LianeGame_OnActorKilled__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/LianeGame",
				PKG_CompiledIn | 0x00000000,
				0xD4183E36,
				0xE0B53924,
				SingletonFuncArray, ARRAY_COUNT(SingletonFuncArray),
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
