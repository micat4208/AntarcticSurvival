#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Enum/DropObjectType.h"

#include "DropObjectInfo.generated.h"

// 해당 구조체 타입에 대해 리플렉션 시스템을 지원하도록 합니다.
/// - BlueprintType : 블루 프린트에서도 사용 가능하도록 합니다.
USTRUCT(BlueprintType)
struct ANTARCTICSURVIVAL_API FDropObjectInfo :
	public FTableRowBase
	/// - FTableRowBase : 테이블 행에 표시될 데이터의 기반 형태를 작성할 수 있는 타입입니다.
	/// - 이 형식을 사용하려면 [DataTable.h] 를 포함시켜야 합니다.
{
	GENERATED_USTRUCT_BODY()
	// - 구조체의 경우 GENERATED_USTRUCT_BODY() 를 작성합니다.

public:
	// 오브젝트 타입을 정의합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "기본")
	EDropObjectType DropObjectType;

	// 떨어지는 오브젝트에 사용될 Static Mesh 애셋을 나타냅니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "기본")
	class UStaticMesh * DropobjectStaticMesh;

	// 겹쳤을 때 변경할 배고픔 게이지 값입니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "변경 값")
	float ChangeHungryValue;
};


// 데이터 테이블 형식으로 사용되는 구조체에 멤버를 추가하는 경우
/// - 에디터 종료
/// - 멤버 추가
/// - Visual Studio 에서 컴파일
/// - 엔진 구동