#pragma once

//#include "CoreMinimal.h"
/// - 언리얼 오브젝트가 동작할 수 있는 최소 기능만 선언된 헤더

#include "EngineMinimal.h"


#ifndef FN_PTR_DEFINE
#define FN_PTR_DEFINE

#define Action(fnPtrName, ParamTypes) void(*fnPtrName)ParamTypes
#define Func(RetType, fnPtrName, ParamTypes) RetType(*fnPtrName)ParamTypes
#endif


// Unreal Script
// 리플렉션 시스템(Property System) 을 지원합니다.
// 리플렉션
// 런타임중 자신을 조사할 수 있는 기능
// 매크로 함수 형식으로 구현되어 있습니다.
/// - 마크업 종류
///   - UENUM(), UCLASS(), USTRUCT(), UFUNCTION(), UPROPERTY()
//  헤더에 Property System 을 지원하는 형식으로 마킹 시키는 방법
/// - "fileName.generated.h" 를 포함시킵니다.
/// - 포함 구문 최하단에 작성합니다.
// Unreal GC System
/// - UObject 한정으로 더 이상 필요 없어진 객체를 자동으로 해제합니다.

// UObject : 언리얼 오브젝트
/// - 언리얼 엔진의 관리를 받는 객체를 의미합니다.
/// - UHT : 의 도움을 받아야 UObject 를 생성할 수 있음!
/// - UObject 규격에 맞게 작성하여 UHT 도움을 받는 방법
///		- "fileName.generated.h" 를 포함시킵니다.
///     - 마크업 작성 (ex : UCLASS())
///		- UObject 접두사 작성 (ex : U, A, F, I, E)
///     - UObject 를 기반으로 두는 클래스를 상속받습니다.
///     - GENERATED_BODY() / GENERATED_USTRUCT_BODY()

// Unreal 이 권고하는 변수를 선언할 때 사용하는 자료형
/// - 정수 : 코어 데이터 형식을 사용합니다.
/// - int8  : __int8
/// - int16 : __int16
/// - int32 : __int32
/// - int64 : __int64
/// - uint8  : unsigned __int8
/// - uint16 : unsigned __int16
/// - uint32 : unsigned __int32
/// - uint64 : unsigned __int64
///
/// - 문자
/// - TCHAR - char / wchar_t
///
/// - 문자열
/// - FString : 일반적인 문자열을 저장할 수 있는 타입
/// - FName : 어떠한 객체의 이름에 사용되는 형식
///   - 대소문자를 구문하지 않습니다.
///   - IsNone() 을 통해 빈 문자열임을 확인합니다.
/// - FText : 현지화 가능 텍스트에 사용되는 타입
///   - 보통 UI 에 표시되는 문자열에 사용되며,
///     다른 사용자에게 다른 언어로 번역될 수 있도록 합니다.

// 문자열 변환
/// - FName to FString : FNameInst.ToString()
/// - FName to FText   : FText::FromName(FNameInst)		(변환 후 자동 현지화가 되지 않을 수 있음.)
///
/// - FString to FName : FName(*FStringInst)			(변환 후 대소문자를 구분하지 않게 됨.)
/// - FString to FText : FText::FromString(FStringInst)	(변환 후 자동 현지화가 되지 않을 수 있음.)
///
/// - FText to FString : FTextInst.ToString()			(일부 언어에서 정상적으로 변환되지 않을 수 있음.)
/// - FText to FName   : FName(*FTextInst.ToString())	(일부 언어에서 정상적으로 변환되지 않을 수 있음.)
///														(변환 후 대소문자를 구분하지 않게 됨.)

// 언리얼 작명 규칙
/// - 파스칼, 헝가리안





