// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USoundWave;
struct FSoundResult;
#ifdef LIANEGAME_LGGameInstance_generated_h
#error "LGGameInstance.generated.h already included, missing '#pragma once' in LGGameInstance.h"
#endif
#define LIANEGAME_LGGameInstance_generated_h

#define LianeGame_Source_LianeGame_LGGameInstance_h_15_GENERATED_BODY \
	friend LIANEGAME_API class UScriptStruct* Z_Construct_UScriptStruct_FSoundResult(); \
	LIANEGAME_API static class UScriptStruct* StaticStruct();


#define LianeGame_Source_LianeGame_LGGameInstance_h_44_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetSoundWaveFromList) \
	{ \
		P_GET_SOFTOBJECT(TSoftObjectPtr<USoundWave>,Z_Param_SoundWaveAsset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FSoundResult*)Z_Param__Result=P_THIS->GetSoundWaveFromList(Z_Param_SoundWaveAsset); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddToSoundWaveList) \
	{ \
		P_GET_SOFTOBJECT(TSoftObjectPtr<USoundWave>,Z_Param_SoundWaveAsset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FSoundResult*)Z_Param__Result=P_THIS->AddToSoundWaveList(Z_Param_SoundWaveAsset); \
		P_NATIVE_END; \
	}


#define LianeGame_Source_LianeGame_LGGameInstance_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetSoundWaveFromList) \
	{ \
		P_GET_SOFTOBJECT(TSoftObjectPtr<USoundWave>,Z_Param_SoundWaveAsset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FSoundResult*)Z_Param__Result=P_THIS->GetSoundWaveFromList(Z_Param_SoundWaveAsset); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddToSoundWaveList) \
	{ \
		P_GET_SOFTOBJECT(TSoftObjectPtr<USoundWave>,Z_Param_SoundWaveAsset); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FSoundResult*)Z_Param__Result=P_THIS->AddToSoundWaveList(Z_Param_SoundWaveAsset); \
		P_NATIVE_END; \
	}


#define LianeGame_Source_LianeGame_LGGameInstance_h_44_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULGGameInstance(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ULGGameInstance(); \
public: \
	DECLARE_CLASS(ULGGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ULGGameInstance) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LGGameInstance_h_44_INCLASS \
private: \
	static void StaticRegisterNativesULGGameInstance(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ULGGameInstance(); \
public: \
	DECLARE_CLASS(ULGGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ULGGameInstance) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LGGameInstance_h_44_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULGGameInstance(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULGGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULGGameInstance(ULGGameInstance&&); \
	NO_API ULGGameInstance(const ULGGameInstance&); \
public:


#define LianeGame_Source_LianeGame_LGGameInstance_h_44_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULGGameInstance(ULGGameInstance&&); \
	NO_API ULGGameInstance(const ULGGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULGGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULGGameInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ULGGameInstance)


#define LianeGame_Source_LianeGame_LGGameInstance_h_44_PRIVATE_PROPERTY_OFFSET
#define LianeGame_Source_LianeGame_LGGameInstance_h_41_PROLOG
#define LianeGame_Source_LianeGame_LGGameInstance_h_44_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LGGameInstance_h_44_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LGGameInstance_h_44_RPC_WRAPPERS \
	LianeGame_Source_LianeGame_LGGameInstance_h_44_INCLASS \
	LianeGame_Source_LianeGame_LGGameInstance_h_44_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LianeGame_Source_LianeGame_LGGameInstance_h_44_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LGGameInstance_h_44_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LGGameInstance_h_44_RPC_WRAPPERS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LGGameInstance_h_44_INCLASS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LGGameInstance_h_44_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LianeGame_Source_LianeGame_LGGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
