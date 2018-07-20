// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIANEGAME_LianeGameCharacter_generated_h
#error "LianeGameCharacter.generated.h already included, missing '#pragma once' in LianeGameCharacter.h"
#endif
#define LIANEGAME_LianeGameCharacter_generated_h

#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_RPC_WRAPPERS
#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALianeGameCharacter(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ALianeGameCharacter(); \
public: \
	DECLARE_CLASS(ALianeGameCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ALianeGameCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_INCLASS \
private: \
	static void StaticRegisterNativesALianeGameCharacter(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ALianeGameCharacter(); \
public: \
	DECLARE_CLASS(ALianeGameCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ALianeGameCharacter) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALianeGameCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALianeGameCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALianeGameCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALianeGameCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALianeGameCharacter(ALianeGameCharacter&&); \
	NO_API ALianeGameCharacter(const ALianeGameCharacter&); \
public:


#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALianeGameCharacter(ALianeGameCharacter&&); \
	NO_API ALianeGameCharacter(const ALianeGameCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALianeGameCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALianeGameCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALianeGameCharacter)


#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ALianeGameCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ALianeGameCharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__TKCamera() { return STRUCT_OFFSET(ALianeGameCharacter, TKCamera); } \
	FORCEINLINE static uint32 __PPO__PhysicsHandle() { return STRUCT_OFFSET(ALianeGameCharacter, PhysicsHandle); }


#define LianeGame_Source_LianeGame_LianeGameCharacter_h_14_PROLOG
#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LianeGameCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LianeGameCharacter_h_17_RPC_WRAPPERS \
	LianeGame_Source_LianeGame_LianeGameCharacter_h_17_INCLASS \
	LianeGame_Source_LianeGame_LianeGameCharacter_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LianeGame_Source_LianeGame_LianeGameCharacter_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LianeGameCharacter_h_17_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LianeGameCharacter_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LianeGameCharacter_h_17_INCLASS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LianeGameCharacter_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LianeGame_Source_LianeGame_LianeGameCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
