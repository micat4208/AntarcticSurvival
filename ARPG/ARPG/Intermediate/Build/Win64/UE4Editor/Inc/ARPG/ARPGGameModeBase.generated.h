// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ARPG_ARPGGameModeBase_generated_h
#error "ARPGGameModeBase.generated.h already included, missing '#pragma once' in ARPGGameModeBase.h"
#endif
#define ARPG_ARPGGameModeBase_generated_h

#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_RPC_WRAPPERS
#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAARPGGameModeBase(); \
	friend struct Z_Construct_UClass_AARPGGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AARPGGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(AARPGGameModeBase)


#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAARPGGameModeBase(); \
	friend struct Z_Construct_UClass_AARPGGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AARPGGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ARPG"), NO_API) \
	DECLARE_SERIALIZER(AARPGGameModeBase)


#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AARPGGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AARPGGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AARPGGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AARPGGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AARPGGameModeBase(AARPGGameModeBase&&); \
	NO_API AARPGGameModeBase(const AARPGGameModeBase&); \
public:


#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AARPGGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AARPGGameModeBase(AARPGGameModeBase&&); \
	NO_API AARPGGameModeBase(const AARPGGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AARPGGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AARPGGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AARPGGameModeBase)


#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET
#define ARPG_Source_ARPG_ARPGGameModeBase_h_12_PROLOG
#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_ARPGGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_ARPGGameModeBase_h_15_RPC_WRAPPERS \
	ARPG_Source_ARPG_ARPGGameModeBase_h_15_INCLASS \
	ARPG_Source_ARPG_ARPGGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ARPG_Source_ARPG_ARPGGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ARPG_Source_ARPG_ARPGGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	ARPG_Source_ARPG_ARPGGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ARPG_Source_ARPG_ARPGGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	ARPG_Source_ARPG_ARPGGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ARPG_API UClass* StaticClass<class AARPGGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ARPG_Source_ARPG_ARPGGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
