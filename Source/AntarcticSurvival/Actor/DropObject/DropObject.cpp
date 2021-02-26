#include "DropObject.h"

#include "GameFramework/DamageType.h"
#include "GameFramework/RotatingMovementComponent.h"

#include "Kismet/GameplayStatics.h"

#include "Struct/DropObjectInfo/DropObjectInfo.h"




ADropObject::ADropObject()
{
	PrimaryActorTick.bCanEverTick = true;

	// StaticMeshComponent �� �߰��մϴ�.
	DropObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DROP_OBJ_MESH"));

	RotatingMovement = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("ROTATING_MOVEMENT"));

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

	// �����, ȸ���� ����
	ChangeHungryValue = dropObjInfo->ChangeHungryValue;

	// ������Ʈ Ÿ�� ����
	DropObjectType = dropObjInfo->DropObjectType;

	RotatingMovement->RotationRate = (DropObjectType == EDropObjectType::DT_Fish) ?
		FRotator::ZeroRotator : FRotator(0.0f, 0.0f, -180.0f);

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
		// ����� / ȸ������ �����մϴ�.
		float addDamage = (DropObjectType == EDropObjectType::DT_Fish) ?
			ChangeHungryValue : -ChangeHungryValue;

		// �÷��̾� ĳ���Ϳ��� ������� ���մϴ�.
		UGameplayStatics::ApplyDamage(
			OtherActor,
			addDamage,
			nullptr,
			this,
			UDamageType::StaticClass());
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