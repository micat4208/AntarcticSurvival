#include "PlayerCharacter.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// 펭귄 SkeletalMesh Asset
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(
		TEXT("SkeletalMesh'/Game/Resources/Character/SK_Penguin.SK_Penguin'"));

	// 펭귄 SkeletalMesh Asset 을 성공적으로 찾았다면
	if (SK_BODY.Succeeded())
	{
		// 캐릭터 Skeletal Mesh 를 찾은 SK_BODY 로 설정합니다.
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
		/// - GetMesh() : Character 클래스에 내장되어있는 SkeletalMesh Component 객체를 반환합니다.

		// Skeletal Mesh Component 의 상대 위치를 설정합니다.
		//GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -88.0f));

		// Skeletal Mesh Component 의 상대 회전을 설정합니다.
		//GetMesh()->SetRelativeRotation(FRotator(0.0f, 0.0f, -90.0f));

		// Skeletal Mesh Component 의 상대 위치 / 회전을 설정합니다.
		GetMesh()->SetRelativeLocationAndRotation(
			FVector::UpVector * -88.0f,
			FRotator(0.0f, -90.0f, 0.0f));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerCharacter.cpp :: %d LINE :: SK_BODY is not Loaded!"), 
			__LINE__);
		// - UE_LOG(카테고리, 레벨, 내용)
		/// - 카테고리 : 로그의 카테고리를 설정합니다.
		/// - 레벨 : 로그의 수준을 설정합니다.
		///   - Fatal : 로그 파일과 콘솔에 항상 출력되며, 프로그램이 종료됩니다.
		///   - Error : 적색으로 콘솔과 파일에 출력됩니다.
		///   - Warning : 황색으로 콘솔과 파일에 출력됩니다.
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

