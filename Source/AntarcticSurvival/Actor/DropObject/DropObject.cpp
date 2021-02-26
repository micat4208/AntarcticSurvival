#include "DropObject.h"

#include "Kismet/GameplayStatics.h"

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
		// 액터를 제거합니다.
		Destroy();
		/// - 만약 다른 액터를 제거하고 싶을 경우 
		///   GetWorld()->DestroyActor() 를 사용합니다.
	}

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


void ADropObject::AddDamage(
	UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// 플레이어 캐릭터와 겹쳤을 경우
	if (OtherActor->ActorHasTag(TEXT("PlayerCharacter")))
	{

		// 플레이어 캐릭터에게 대미지를 가합니다.
		//UGameplayStatics::ApplyDamage();
		/// ApplyDamage(AActor *					DamagedActor
		///             float						BaseDamage
		///             AController*				EventInstigator
		///             AActor *					DamageCauser
		///             TSubclassOf<UDamageType>	DamageTypeClass)
		/// - DamagedActor : 대미지를 가할 액터를 나타냅니다.
		/// - BaseDamage : 가할 대미지를 나타냅니다.
		/// - EventInstigator : 피해를 가한 컨트롤러를 나타냅니다.
		/// - DamageCauser : 피해를 입히는 객체를 나타냅니다.
		/// - DamageTypeClass : 대미지 타입을 설명하는 UClass 를 전달합니다.

		// 액터를 제거합니다.
		Destroy();
	}
}