#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// ��� SkeletalMesh Asset
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("SkeletalMesh'/Game/Resources/Character/SK_Penguin.SK_Penguin'"));

	// ��� SkeletalMesh Asset �� ���������� ã�Ҵٸ�
	if (SK_BODY.Succeeded())
	{
		// ĳ���� Skeletal Mesh �� ã�� SK_BODY �� �����մϴ�.
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
		/// - GetMesh() : Character Ŭ������ ����Ǿ��ִ� SkeletalMesh Component ��ü�� ��ȯ�մϴ�.

		// Skeletal Mesh Component �� ��� ��ġ�� �����մϴ�.
		//GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -88.0f));

		// Skeletal Mesh Component �� ��� ȸ���� �����մϴ�.
		//GetMesh()->SetRelativeRotation(FRotator(0.0f, 0.0f, -90.0f));

		// Skeletal Mesh Component �� ��� ��ġ / ȸ���� �����մϴ�.
		GetMesh()->SetRelativeLocationAndRotation(
			FVector::UpVector * -88.0f,
			FRotator(0.0f, -90.0f, 0.0f));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerCharacter.cpp :: %d LINE :: SK_BODY is not Loaded!"), 
			__LINE__);
		// - UE_LOG(ī�װ�, ����, ����)
		/// - ī�װ� : �α��� ī�װ��� �����մϴ�.
		/// - ���� : �α��� ������ �����մϴ�.
		///   - Fatal : �α� ���ϰ� �ֿܼ� �׻� ��µǸ�, ���α׷��� ����˴ϴ�.
		///   - Error : �������� �ְܼ� ���Ͽ� ��µ˴ϴ�.
		///   - Warning : Ȳ������ �ְܼ� ���Ͽ� ��µ˴ϴ�.
	}



}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

