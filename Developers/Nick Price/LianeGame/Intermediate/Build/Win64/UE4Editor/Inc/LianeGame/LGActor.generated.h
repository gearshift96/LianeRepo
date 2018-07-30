// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIANEGAME_LGActor_generated_h
#error "LGActor.generated.h already included, missing '#pragma once' in LGActor.h"
#endif
#define LIANEGAME_LGActor_generated_h

#define LianeGame_Source_LianeGame_LGActor_h_14_RPC_WRAPPERS
#define LianeGame_Source_LianeGame_LGActor_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define LianeGame_Source_LianeGame_LGActor_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALGActor(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ALGActor(); \
public: \
	DECLARE_CLASS(ALGActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ALGActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LGActor_h_14_INCLASS \
private: \
	static void StaticRegisterNativesALGActor(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ALGActor(); \
public: \
	DECLARE_CLASS(ALGActor, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ALGActor) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LGActor_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALGActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALGActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALGActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALGActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALGActor(ALGActor&&); \
	NO_API ALGActor(const ALGActor&); \
public:


#define LianeGame_Source_LianeGame_LGActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALGActor(ALGActor&&); \
	NO_API ALGActor(const ALGActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALGActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALGActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALGActor)


#define LianeGame_Source_LianeGame_LGActor_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SoundComponentAssetList() { return STRUCT_OFFSET(ALGActor, SoundComponentAssetList); } \
	FORCEINLINE static uint32 __PPO__FireAndForgetSoundAssetList() { return STRUCT_OFFSET(ALGActor, FireAndForgetSoundAssetList); }


#define LianeGame_Source_LianeGame_LGActor_h_11_PROLOG
#define LianeGame_Source_LianeGame_LGActor_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LGActor_h_14_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LGActor_h_14_RPC_WRAPPERS \
	LianeGame_Source_LianeGame_LGActor_h_14_INCLASS \
	LianeGame_Source_LianeGame_LGActor_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LianeGame_Source_LianeGame_LGActor_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LGActor_h_14_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LGActor_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LGActor_h_14_INCLASS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LGActor_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LianeGame_Source_LianeGame_LGActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
