// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LIANEGAME_LGWeapon_generated_h
#error "LGWeapon.generated.h already included, missing '#pragma once' in LGWeapon.h"
#endif
#define LIANEGAME_LGWeapon_generated_h

#define LianeGame_Source_LianeGame_LGWeapon_h_14_RPC_WRAPPERS
#define LianeGame_Source_LianeGame_LGWeapon_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define LianeGame_Source_LianeGame_LGWeapon_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALGWeapon(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ALGWeapon(); \
public: \
	DECLARE_CLASS(ALGWeapon, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ALGWeapon) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LGWeapon_h_14_INCLASS \
private: \
	static void StaticRegisterNativesALGWeapon(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_ALGWeapon(); \
public: \
	DECLARE_CLASS(ALGWeapon, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(ALGWeapon) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LianeGame_Source_LianeGame_LGWeapon_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALGWeapon(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALGWeapon) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALGWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALGWeapon); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALGWeapon(ALGWeapon&&); \
	NO_API ALGWeapon(const ALGWeapon&); \
public:


#define LianeGame_Source_LianeGame_LGWeapon_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALGWeapon(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALGWeapon(ALGWeapon&&); \
	NO_API ALGWeapon(const ALGWeapon&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALGWeapon); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALGWeapon); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALGWeapon)


#define LianeGame_Source_LianeGame_LGWeapon_h_14_PRIVATE_PROPERTY_OFFSET
#define LianeGame_Source_LianeGame_LGWeapon_h_11_PROLOG
#define LianeGame_Source_LianeGame_LGWeapon_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LGWeapon_h_14_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LGWeapon_h_14_RPC_WRAPPERS \
	LianeGame_Source_LianeGame_LGWeapon_h_14_INCLASS \
	LianeGame_Source_LianeGame_LGWeapon_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LianeGame_Source_LianeGame_LGWeapon_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_LGWeapon_h_14_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_LGWeapon_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LGWeapon_h_14_INCLASS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_LGWeapon_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LianeGame_Source_LianeGame_LGWeapon_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
