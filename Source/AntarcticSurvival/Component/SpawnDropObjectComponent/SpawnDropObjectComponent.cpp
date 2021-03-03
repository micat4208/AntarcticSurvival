#include "SpawnDropObjectComponent.h"

#include "Engine/DataTable.h"

#include "Actor/DropObject/DropObject.h"

#include "Struct/DropObjectInfo/DropObjectInfo.h"


USpawnDropObjectComponent::USpawnDropObjectComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UDataTable> DT_DROP_OBJECT_INFO(
		TEXT("DataTable'/Game/DataTables/DT_DropObjectInfo.DT_DropObjectInfo'"));
	if (DT_DROP_OBJECT_INFO.Succeeded())
		DT_DropObjectInfo = DT_DROP_OBJECT_INFO.Object;

	MinDelay = 1.0f;
	MaxDelay = 0.02f;

	SpawnMaxLeftY = 981.0f;
	SpawnMaxRightY = -815.9;
}

void USpawnDropObjectComponent::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnDelay = MinDelay;

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

	SpawnDropObject();
}

void USpawnDropObjectComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ChangeDelayFaster(DeltaTime);
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

	FVector spawnLocation =
		GetOwner()->GetActorLocation() +
		(FMath::FRandRange(SpawnMaxRightY, SpawnMaxLeftY) * FVector::RightVector);

	// DropObject ���͸� �����մϴ�.
	ADropObject * newDropObject = GetWorld()->SpawnActor<ADropObject>(
		spawnLocation,
		FRotator::ZeroRotator);
	/// - SpawnActor<T>(FVector location, FRotator rotation) : T ������ ���͸�
	///   location ��ġ�� �����ϰ� rotation ȸ�������� �����մϴ�.

	// DropObject �ʱ�ȭ
	newDropObject->InitializeDropObject(
		300.0f + (300.0f * (MinDelay - SpawnDelay)),
		dropObjInfo);


	FTimerHandle hSpawnDropObjTimer;
	GetWorld()->GetTimerManager().SetTimer(
		hSpawnDropObjTimer,
		this, 
		&USpawnDropObjectComponent::SpawnDropObject, 
		SpawnDelay,
		false);
	// Ÿ�̸� : ������ �ð����� Ư���� ������ �����ϴ� ���
	/// - Ÿ�̸Ӱ� ������ �ൿ�� �Լ� ���� : void()

}

void USpawnDropObjectComponent::ChangeDelayFaster(float dt)
{
	UE_LOG(LogTemp, Warning, TEXT("SpawnDelay = %.2f"), SpawnDelay);

	if (SpawnDelay > MaxDelay)
		SpawnDelay -= dt * 0.05f;

	else SpawnDelay = MaxDelay;
}
