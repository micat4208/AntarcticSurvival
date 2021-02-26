#include "DropObject.h"

#include "Kismet/GameplayStatics.h"

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

	DropObjectMesh->OnComponentBeginOverlap.AddDynamic(
		this, &ADropObject::AddDamage);
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

	if (newLocation.Z < -250.0f)
	{
		// ���͸� �����մϴ�.
		Destroy();
		/// - ���� �ٸ� ���͸� �����ϰ� ���� ��� 
		///   GetWorld()->DestroyActor() �� ����մϴ�.
	}

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


void ADropObject::AddDamage(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// �÷��̾� ĳ���Ϳ� ������ ���
	if (OtherActor->ActorHasTag(TEXT("PlayerCharacter")))
	{

		// �÷��̾� ĳ���Ϳ��� ������� ���մϴ�.
		//UGameplayStatics::ApplyDamage();
		/// ApplyDamage(AActor *					DamagedActor
		///             float						BaseDamage
		///             AController*				EventInstigator
		///             AActor *					DamageCauser
		///             TSubclassOf<UDamageType>	DamageTypeClass)
		/// - DamagedActor : ������� ���� ���͸� ��Ÿ���ϴ�.
		/// - BaseDamage : ���� ������� ��Ÿ���ϴ�.
		/// - EventInstigator : ���ظ� ���� ��Ʈ�ѷ��� ��Ÿ���ϴ�.
		/// - DamageCauser : ���ظ� ������ ��ü�� ��Ÿ���ϴ�.
		/// - DamageTypeClass : ����� Ÿ���� �����ϴ� UClass �� �����մϴ�.

		// ���͸� �����մϴ�.
		Destroy();
	}
}