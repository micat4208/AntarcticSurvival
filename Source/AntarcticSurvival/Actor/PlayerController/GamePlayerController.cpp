#include "GamePlayerController.h"
#include "Actor/PlayerCharacter/PlayerCharacter.h"

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

}

void AGamePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	PlayerCharacter = Cast<APlayerCharacter>(aPawn);

	// 카메라 뷰를 설정합니다.
	SetCameraView();
}

void AGamePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//RotateController();
}

void AGamePlayerController::SetCameraView()
{
	// 찾은 액터를 저장할 배열
	TArray<AActor*> findActors;
	/// - 언리얼에서 제공하는 컨테이너
	/// - TArray : 동적으로 크기를 조절할 수 있는 배열
	///   - UPROPERTY() 와 함께 선언될 수 있습니다.
	/// - TSet : 저장 순서가 유지되며, 중복 저장되지 않습니다.
	/// - TMap : 키와 값이 저장되며, 키는 중복 저장되지 않습니다.

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Camera"), findActors);
	/// - UGameplayStatics : 유틸성 정적 메서드를 제공하는 클래스입니다.
	/// - GetAllActorsWithTag(WorldContextObject, Tag, OutActors) : Tag 를 갖는 액터를 월드에서 찾아
	///   OutActors 에 저장합니다.

	// 액터를 찾지 못했다면
	if (findActors.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("GamePlayerController.cpp :: %d LINE :: findActors elem is 0!"), 
			__LINE__);
		return;
	}

	SetViewTargetWithBlend(findActors[0]);
	/// - SetViewTargetWithBlend(NewViewTarget) 
	/// - 뷰 타깃을 NewViewTarget 으로 설정합니다.
}


void AGamePlayerController::RotateController()
{
	SetControlRotation(
		FRotator(0.0f, PlayerCharacter->GetHorizontalInputValue() * 90.0f, 0.0f));
}
