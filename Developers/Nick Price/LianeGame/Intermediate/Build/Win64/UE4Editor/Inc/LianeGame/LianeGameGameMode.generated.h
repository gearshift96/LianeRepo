// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AController;
#ifdef LIANEGAME_LianeGameGameMode_generated_h
#error "LianeGameGameMode.generated.h already included, missing '#pragma once' in LianeGameGameMode.h"
#endif
#define LIANEGAME_LianeGameGameMode_generated_h

#define LianeGame_Source_LianeGame_LianeGameGameMode_h_8_DELEGATE \
struct _Script_LianeGame_eventOnActorKilled_Parms \
{ \
	AActor* VictimActor; \
	AActor* KillerActor; \
	AController* KillerController; \
}; \
static inline void FOnActorKilled_DelegateWrapper(const FMulticastScriptDelegate& OnActorKilled, AActor* VictimActor, AActor* KillerActor, AController* KillerController) \
{ \
	_Script_LianeGame_eventOnActorKilled_Parms Parms; \
	Parms.VictimActor=VictimActor; \
	Parms.KillerActor=KillerActor; \
	Parms.KillerController=KillerController; \
	OnActorKilled.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_RPC_WRAPPERS
#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALianeGameGameMode(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ALianeGameGameMode(); \
public: \
	DECLARE_CLASS(ALianeGameGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ALianeGameGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_INCLASS \
private: \
	static void StaticRegisterNativesALianeGameGameMode(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ALianeGameGameMode(); \
public: \
	DECLARE_CLASS(ALianeGameGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ALianeGameGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALianeGameGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALianeGameGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALianeGameGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALianeGameGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALianeGameGameMode(ALianeGameGameMode&&); \
	NO_API ALianeGameGameMode(const ALianeGameGameMode&); \
public:


#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALianeGameGameMode(ALianeGameGameMode&&); \
	NO_API ALianeGameGameMode(const ALianeGameGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALianeGameGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALianeGameGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALianeGameGameMode)


#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_PRIVATE_PROPERTY_OFFSET
#define LianeGame_Source_LianeGame_LianeGameGameMode_h_10_PROLOG
#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LianeGameGameMode_h_13_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LianeGameGameMode_h_13_RPC_WRAPPERS \
	LianeGame_Source_LianeGame_LianeGameGameMode_h_13_INCLASS \
	LianeGame_Source_LianeGame_LianeGameGameMode_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LianeGame_Source_LianeGame_LianeGameGameMode_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LianeGameGameMode_h_13_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LianeGameGameMode_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LianeGameGameMode_h_13_INCLASS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LianeGameGameMode_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LianeGame_Source_LianeGame_LianeGameGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
