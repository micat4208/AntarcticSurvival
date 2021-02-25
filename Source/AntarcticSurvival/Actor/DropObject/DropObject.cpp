#include "DropObject.h"

#include "Struct/DropObjectInfo/DropObjectInfo.h"


ADropObject::ADropObject()
{
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponent 를 추가합니다.
	DropObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DROP_OBJ_MESH"));

	// 추가한 StaticMeshComponent 를 액터를 대표하는 컴포넌트로 지정합니다.
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
	// 떨어지는 속력 설정
	FallDownSpeed = fallDownSpeed;

	// Static Mesh 애셋 적용
	DropObjectMesh->SetStaticMesh(dropObjInfo->DropobjectStaticMesh);

	// Static Mesh Component 의 Collision Preset 속성 변경
	DropObjectMesh->SetCollisionProfileName(FName(TEXT("OverlapAllDynamic")));


}
