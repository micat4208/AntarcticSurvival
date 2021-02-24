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
	
	// DataTable ���� ���� �̸����� ����ϴ�.
	for (FName rowName : DT_DropObjectInfo->GetRowNames())
	{
		// FindRow �޼��带 �̿��Ͽ� ���� ã�� ��, ������ ���� ���
		// ���� ������ �˸� ���ڿ� ������ �����մϴ�.
		FString contextString;

		// DataTable ���� �̸��� �̿��Ͽ� ���� ã���ϴ�.
		auto info = DT_DropObjectInfo->FindRow<FDropObjectInfo>(rowName, contextString);

		//if (info->DropObjectType == EDropObjectType::DT_Fish)
		//	FishObjInfos.Add(info);
		//else TrashObjInfos.Add(info);

		// ������ �߰��� �迭�� ���� ������
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
	// ������ DropObject �� Ÿ���� fishDropPer �� ���� ��ȯ�ϴ� �Լ�.
	Func(EDropObjectType, fnGetRandomDropType, (float)) = [](float fishDropPer)
	{
		return (FMath::FRandRange(1.0f, 100.0f) <= fishDropPer) ?
			EDropObjectType::DT_Fish : EDropObjectType::DT_Trash;
	};

	// dropObjType �� ���� ������ DropObject ������ ����ϴ�.
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
		/// - TArrayInstance.Num() : �迭�� ��� ������ ��ȯ�մϴ�.
	};

#pragma endregion

	// ������ DropObj �� Ÿ���� �����մϴ�.
	EDropObjectType dropObjType = fnGetRandomDropType(FishDropPercentage);

	// ������ DropObj �� ������ ����ϴ�.
	FDropObjectInfo* dropObjInfo = fnGetRandomDropObjInfo(
		dropObjType, &FishObjInfos, &TrashObjInfos);

	// DropObject ���͸� ����


}