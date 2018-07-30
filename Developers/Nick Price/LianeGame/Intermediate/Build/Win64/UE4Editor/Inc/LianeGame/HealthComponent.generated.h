// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UHealthComponent;
class UDamageType;
class AController;
class AActor;
#ifdef LIANEGAME_HealthComponent_generated_h
#error "HealthComponent.generated.h already included, missing '#pragma once' in HealthComponent.h"
#endif
#define LIANEGAME_HealthComponent_generated_h

#define LianeGame_Source_LianeGame_HealthComponent_h_10_DELEGATE \
struct _Script_LianeGame_eventOnHealthChangedSignature_Parms \
{ \
	UHealthComponent* OwningHealthComp; \
	float Health; \
	float HealthDelta; \
	const UDamageType* DamageType; \
	AController* InstigatedBy; \
	AActor* DamageCauser; \
}; \
static inline void FOnHealthChangedSignature_DelegateWrapper(const FMulticastScriptDelegate& OnHealthChangedSignature, UHealthComponent* OwningHealthComp, float Health, float HealthDelta, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser) \
{ \
	_Script_LianeGame_eventOnHealthChangedSignature_Parms Parms; \
	Parms.OwningHealthComp=OwningHealthComp; \
	Parms.Health=Health; \
	Parms.HealthDelta=HealthDelta; \
	Parms.DamageType=DamageType; \
	Parms.InstigatedBy=InstigatedBy; \
	Parms.DamageCauser=DamageCauser; \
	OnHealthChangedSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define LianeGame_Source_LianeGame_HealthComponent_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIsFriendly) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ActorA); \
		P_GET_OBJECT(AActor,Z_Param_ActorB); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UHealthComponent::IsFriendly(Z_Param_ActorA,Z_Param_ActorB); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeal) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HealAmount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Heal(Z_Param_HealAmount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleTakeAnyDamage) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DamagedActor); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Damage); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleTakeAnyDamage(Z_Param_DamagedActor,Z_Param_Damage,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnRep_Health) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_OldHealth); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnRep_Health(Z_Param_OldHealth); \
		P_NATIVE_END; \
	}


#define LianeGame_Source_LianeGame_HealthComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsFriendly) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_ActorA); \
		P_GET_OBJECT(AActor,Z_Param_ActorB); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UHealthComponent::IsFriendly(Z_Param_ActorA,Z_Param_ActorB); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHeal) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_HealAmount); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Heal(Z_Param_HealAmount); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHandleTakeAnyDamage) \
	{ \
		P_GET_OBJECT(AActor,Z_Param_DamagedActor); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Damage); \
		P_GET_OBJECT(UDamageType,Z_Param_DamageType); \
		P_GET_OBJECT(AController,Z_Param_InstigatedBy); \
		P_GET_OBJECT(AActor,Z_Param_DamageCauser); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->HandleTakeAnyDamage(Z_Param_DamagedActor,Z_Param_Damage,Z_Param_DamageType,Z_Param_InstigatedBy,Z_Param_DamageCauser); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOnRep_Health) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_OldHealth); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->OnRep_Health(Z_Param_OldHealth); \
		P_NATIVE_END; \
	}


#define LianeGame_Source_LianeGame_HealthComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHealthComponent(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_UHealthComponent(); \
public: \
	DECLARE_CLASS(UHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(UHealthComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define LianeGame_Source_LianeGame_HealthComponent_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUHealthComponent(); \
	friend LIANEGAME_API class UClass* Z_Construct_UClass_UHealthComponent(); \
public: \
	DECLARE_CLASS(UHealthComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LianeGame"), NO_API) \
	DECLARE_SERIALIZER(UHealthComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;


#define LianeGame_Source_LianeGame_HealthComponent_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHealthComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHealthComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHealthComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHealthComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHealthComponent(UHealthComponent&&); \
	NO_API UHealthComponent(const UHealthComponent&); \
public:


#define LianeGame_Source_LianeGame_HealthComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHealthComponent(UHealthComponent&&); \
	NO_API UHealthComponent(const UHealthComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHealthComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHealthComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UHealthComponent)


#define LianeGame_Source_LianeGame_HealthComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(UHealthComponent, Health); } \
	FORCEINLINE static uint32 __PPO__DefaultHealth() { return STRUCT_OFFSET(UHealthComponent, DefaultHealth); }


#define LianeGame_Source_LianeGame_HealthComponent_h_12_PROLOG
#define LianeGame_Source_LianeGame_HealthComponent_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_HealthComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_HealthComponent_h_15_RPC_WRAPPERS \
	LianeGame_Source_LianeGame_HealthComponent_h_15_INCLASS \
	LianeGame_Source_LianeGame_HealthComponent_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LianeGame_Source_LianeGame_HealthComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LianeGame_Source_LianeGame_HealthComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	LianeGame_Source_LianeGame_HealthComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_HealthComponent_h_15_INCLASS_NO_PURE_DECLS \
	LianeGame_Source_LianeGame_HealthComponent_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LianeGame_Source_LianeGame_HealthComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
