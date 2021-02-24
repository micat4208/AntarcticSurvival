#include "SpawnDropObjectComponent.h"

#include "Engine/DataTable.h"

#include "Struct/DropObjectInfo/DropObjectInfo.h"


USpawnDropObjectComponent::USpawnDropObjectComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_DROP_OBJECT_INFO(
		TEXT("DataTable'/Game/DataTables/DT_DropObjectInfo.DT_DropObjectInfo'"));
	if (DT_DROP_OBJECT_INFO.Succeeded())
		DT_DropObjectInfo = DT_DROP_OBJECT_INFO.Object;
}

void USpawnDropObjectComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// DataTable 에서 행의 이름들을 얻습니다.
	for (FName rowName : DT_DropObjectInfo->GetRowNames())
	{
		// FindRow 메서드를 이용하여 행을 찾을 때, 문제가 생길 경우
		// 문제 내용을 알릴 문자열 변수를 선언합니다.
		FString contextString;

		// DataTable 에서 이름을 이용하여 행을 찾습니다.
		auto info = DT_DropObjectInfo->FindRow<FDropObjectInfo>(rowName, contextString);

		//if (info->DropObjectType == EDropObjectType::DT_Fish)
		//	FishObjInfos.Add(info);
		//else TrashObjInfos.Add(info);

		// 내용을 추가할 배열에 대한 참조자
		TArray<FDropObjectInfo*>& targetArray = 
			(info->DropObjectType == EDropObjectType::DT_Fish) ?
			FishObjInfos : TrashObjInfos;

		targetArray.Add(info);
	}
}

void USpawnDropObjectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USpawnDropObjectComponent::SpawnDropObject()
{
#pragma region Functions...
	// 생성할 DropObject 의 타입을 fishDropPer 에 따라 반환하는 함수.
	Func(EDropObjectType, fnGetRandomDropType, (float)) = [](float fishDropPer)
	{
		return (FMath::FRandRange(1.0f, 100.0f) <= fishDropPer) ?
			EDropObjectType::DT_Fish : EDropObjectType::DT_Trash;
	};

	// dropObjType 에 따라 랜덤한 DropObject 정보를 얻습니다.
	Func(FDropObjectInfo*, 
		fnGetRandomDropObjInfo, 
		(EDropObjectType, const TArray<FDropObjectInfo*>*, const TArray<FDropObjectInfo*>*)) =
		[](EDropObjectType dropObjType, 
			const TArray<FDropObjectInfo*>* fishObjInfos,
			const TArray<FDropObjectInfo*>* trashObjInfos)
	{
		const TArray<FDropObjectInfo*>* dropObjInfo = (dropObjType == EDropObjectType::DT_Fish) ?
			fishObjInfos : trashObjInfos;

		return ((*dropObjInfo)[FMath::RandRange(0, dropObjInfo->Num() - 1)]);
		/// - TArrayInstance.Num() : 배열의 요소 개수를 반환합니다.
	};

#pragma endregion

	// 생성할 DropObj 의 타입을 저장합니다.
	EDropObjectType dropObjType = fnGetRandomDropType(FishDropPercentage);

	// 랜덤한 DropObj 의 정보를 얻습니다.
	FDropObjectInfo* dropObjInfo = fnGetRandomDropObjInfo(
		dropObjType, &FishObjInfos, &TrashObjInfos);

	// DropObject 액터를 생성


}