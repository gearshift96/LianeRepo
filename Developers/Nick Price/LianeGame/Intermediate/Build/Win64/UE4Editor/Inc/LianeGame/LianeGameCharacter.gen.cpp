// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "LianeGameCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLianeGameCharacter() {}
// Cross Module References
	LIANEGAME_API UClass* Z_Construct_UClass_ALianeGameCharacter_NoRegister();
	LIANEGAME_API UClass* Z_Construct_UClass_ALianeGameCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_LianeGame();
	LIANEGAME_API UFunction* Z_Construct_UFunction_ALianeGameCharacter_OnHealthChanged();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	LIANEGAME_API UClass* Z_Construct_UClass_UHealthComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPhysicsHandleComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimInstance_NoRegister();
// End Cross Module References
	void ALianeGameCharacter::StaticRegisterNativesALianeGameCharacter()
	{
		UClass* Class = ALianeGameCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHealthChanged", &ALianeGameCharacter::execOnHealthChanged },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ALianeGameCharacter_OnHealthChanged()
	{
		struct LianeGameCharacter_eventOnHealthChanged_Parms
		{
			UHealthComponent* OwningHealthComp;
			float Health;
			float HealthDelta;
			const UDamageType* DamageType;
			AController* InstigatedBy;
			AActor* DamageCauser;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageCauser = { UE4CodeGen_Private::EPropertyClass::Object, "DamageCauser", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LianeGameCharacter_eventOnHealthChanged_Parms, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_InstigatedBy = { UE4CodeGen_Private::EPropertyClass::Object, "InstigatedBy", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LianeGameCharacter_eventOnHealthChanged_Parms, InstigatedBy), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DamageType = { UE4CodeGen_Private::EPropertyClass::Object, "DamageType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(LianeGameCharacter_eventOnHealthChanged_Parms, DamageType), Z_Construct_UClass_UDamageType_NoRegister, METADATA_PARAMS(NewProp_DamageType_MetaData, ARRAY_COUNT(NewProp_DamageType_MetaData)) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HealthDelta = { UE4CodeGen_Private::EPropertyClass::Float, "HealthDelta", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LianeGameCharacter_eventOnHealthChanged_Parms, HealthDelta), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health = { UE4CodeGen_Private::EPropertyClass::Float, "Health", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(LianeGameCharacter_eventOnHealthChanged_Parms, Health), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwningHealthComp_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OwningHealthComp = { UE4CodeGen_Private::EPropertyClass::Object, "OwningHealthComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(LianeGameCharacter_eventOnHealthChanged_Parms, OwningHealthComp), Z_Construct_UClass_UHealthComponent_NoRegister, METADATA_PARAMS(NewProp_OwningHealthComp_MetaData, ARRAY_COUNT(NewProp_OwningHealthComp_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DamageCauser,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InstigatedBy,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DamageType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HealthDelta,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Health,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OwningHealthComp,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ALianeGameCharacter, "OnHealthChanged", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00080401, sizeof(LianeGameCharacter_eventOnHealthChanged_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ALianeGameCharacter_NoRegister()
	{
		return ALianeGameCharacter::StaticClass();
	}
	UClass* Z_Construct_UClass_ALianeGameCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ACharacter,
				(UObject* (*)())Z_Construct_UPackage__Script_LianeGame,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ALianeGameCharacter_OnHealthChanged, "OnHealthChanged" }, // 2150367406
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "LianeGameCharacter.h" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera = { UE4CodeGen_Private::EPropertyClass::Object, "FollowCamera", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(NewProp_FollowCamera_MetaData, ARRAY_COUNT(NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Camera" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom = { UE4CodeGen_Private::EPropertyClass::Object, "CameraBoom", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a001d, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(NewProp_CameraBoom_MetaData, ARRAY_COUNT(NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PhysicsHandle_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Telekinesis" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PhysicsHandle = { UE4CodeGen_Private::EPropertyClass::Object, "PhysicsHandle", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, PhysicsHandle), Z_Construct_UClass_UPhysicsHandleComponent_NoRegister, METADATA_PARAMS(NewProp_PhysicsHandle_MetaData, ARRAY_COUNT(NewProp_PhysicsHandle_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDied_MetaData[] = {
				{ "Category", "Player" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
				{ "ToolTip", "Pawn died previously" },
			};
#endif
			auto NewProp_bDied_SetBit = [](void* Obj){ ((ALianeGameCharacter*)Obj)->bDied = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDied = { UE4CodeGen_Private::EPropertyClass::Bool, "bDied", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000034, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ALianeGameCharacter), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bDied_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bDied_MetaData, ARRAY_COUNT(NewProp_bDied_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthComp_MetaData[] = {
				{ "Category", "Components" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HealthComp = { UE4CodeGen_Private::EPropertyClass::Object, "HealthComp", RF_Public|RF_Transient|RF_MarkAsNative, 0x00200800000b0009, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, HealthComp), Z_Construct_UClass_UHealthComponent_NoRegister, METADATA_PARAMS(NewProp_HealthComp_MetaData, ARRAY_COUNT(NewProp_HealthComp_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponAttachSocketName_MetaData[] = {
				{ "Category", "Player" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_WeaponAttachSocketName = { UE4CodeGen_Private::EPropertyClass::Name, "WeaponAttachSocketName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000030001, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, WeaponAttachSocketName), METADATA_PARAMS(NewProp_WeaponAttachSocketName_MetaData, ARRAY_COUNT(NewProp_WeaponAttachSocketName_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZoomInterpSpeed_MetaData[] = {
				{ "Category", "Player" },
				{ "ClampMax", "100" },
				{ "ClampMin", "0.100000" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZoomInterpSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "ZoomInterpSpeed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, ZoomInterpSpeed), METADATA_PARAMS(NewProp_ZoomInterpSpeed_MetaData, ARRAY_COUNT(NewProp_ZoomInterpSpeed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ZoomedFOV_MetaData[] = {
				{ "Category", "Player" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ZoomedFOV = { UE4CodeGen_Private::EPropertyClass::Float, "ZoomedFOV", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000010001, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, ZoomedFOV), METADATA_PARAMS(NewProp_ZoomedFOV_MetaData, ARRAY_COUNT(NewProp_ZoomedFOV_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_animInstance_MetaData[] = {
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_animInstance = { UE4CodeGen_Private::EPropertyClass::Object, "animInstance", RF_Public|RF_Transient|RF_MarkAsNative, 0x0020080000000000, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, animInstance), Z_Construct_UClass_UAnimInstance_NoRegister, METADATA_PARAMS(NewProp_animInstance_MetaData, ARRAY_COUNT(NewProp_animInstance_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ThrowStrength_MetaData[] = {
				{ "Category", "Telekinesis" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
				{ "ToolTip", "The strength of the telekinesis throw" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ThrowStrength = { UE4CodeGen_Private::EPropertyClass::Float, "ThrowStrength", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, ThrowStrength), METADATA_PARAMS(NewProp_ThrowStrength_MetaData, ARRAY_COUNT(NewProp_ThrowStrength_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TK_Reach_MetaData[] = {
				{ "Category", "Telekinesis" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
				{ "ToolTip", "How far ahead of the player can we reach in cm" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TK_Reach = { UE4CodeGen_Private::EPropertyClass::Float, "TK_Reach", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, TK_Reach), METADATA_PARAMS(NewProp_TK_Reach_MetaData, ARRAY_COUNT(NewProp_TK_Reach_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PullDirection_MetaData[] = {
				{ "Category", "Telekinesis" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
				{ "ToolTip", "The direction which the grabbed object is pulled" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PullDirection = { UE4CodeGen_Private::EPropertyClass::Float, "PullDirection", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, PullDirection), METADATA_PARAMS(NewProp_PullDirection_MetaData, ARRAY_COUNT(NewProp_PullDirection_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[] = {
				{ "Category", "Camera" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
				{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate = { UE4CodeGen_Private::EPropertyClass::Float, "BaseLookUpRate", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, BaseLookUpRate), METADATA_PARAMS(NewProp_BaseLookUpRate_MetaData, ARRAY_COUNT(NewProp_BaseLookUpRate_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[] = {
				{ "Category", "Camera" },
				{ "ModuleRelativePath", "LianeGameCharacter.h" },
				{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate = { UE4CodeGen_Private::EPropertyClass::Float, "BaseTurnRate", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000020015, 1, nullptr, STRUCT_OFFSET(ALianeGameCharacter, BaseTurnRate), METADATA_PARAMS(NewProp_BaseTurnRate_MetaData, ARRAY_COUNT(NewProp_BaseTurnRate_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FollowCamera,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CameraBoom,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PhysicsHandle,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bDied,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HealthComp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WeaponAttachSocketName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZoomInterpSpeed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ZoomedFOV,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_animInstance,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ThrowStrength,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TK_Reach,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PullDirection,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseLookUpRate,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BaseTurnRate,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ALianeGameCharacter>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ALianeGameCharacter::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00800080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				"Game",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALianeGameCharacter, 3016848830);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALianeGameCharacter(Z_Construct_UClass_ALianeGameCharacter, &ALianeGameCharacter::StaticClass, TEXT("/Script/LianeGame"), TEXT("ALianeGameCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALianeGameCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
