#include "DropObject.h"

#include "Struct/DropObjectInfo/DropObjectInfo.h"


ADropObject::ADropObject()
{
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponent �� �߰��մϴ�.
	DropObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DROP_OBJ_MESH"));

	// �߰��� StaticMeshComponent �� ���͸� ��ǥ�ϴ� ������Ʈ�� �����մϴ�.
	SetRootComponent(DropObjectMesh);
}

void ADropObject::BeginPlay()
{
	Super::BeginPlay();
}

void ADropObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FallDown(DeltaTime);
}

void ADropObject::FallDown(float dt)
{
	FVector newLocation = GetActorLocation() +
		(FVector::DownVector * FallDownSpeed * dt);

	SetActorLocation(newLocation);

}

void ADropObject::InitializeDropObject(
	float fallDownSpeed, 
	FDropObjectInfo* dropObjInfo)
{
	// �������� �ӷ� ����
	FallDownSpeed = fallDownSpeed;

	// Static Mesh �ּ� ����
	DropObjectMesh->SetStaticMesh(dropObjInfo->DropobjectStaticMesh);

	// Static Mesh Component �� Collision Preset �Ӽ� ����
	DropObjectMesh->SetCollisionProfileName(FName(TEXT("OverlapAllDynamic")));


}
