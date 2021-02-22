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

	// ī�޶� �並 �����մϴ�.
	SetCameraView();
}

void AGamePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//RotateController();
}

void AGamePlayerController::SetCameraView()
{
	// ã�� ���͸� ������ �迭
	TArray<AActor*> findActors;
	/// - �𸮾󿡼� �����ϴ� �����̳�
	/// - TArray : �������� ũ�⸦ ������ �� �ִ� �迭
	///   - UPROPERTY() �� �Բ� ����� �� �ֽ��ϴ�.
	/// - TSet : ���� ������ �����Ǹ�, �ߺ� ������� �ʽ��ϴ�.
	/// - TMap : Ű�� ���� ����Ǹ�, Ű�� �ߺ� ������� �ʽ��ϴ�.

	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Camera"), findActors);
	/// - UGameplayStatics : ��ƿ�� ���� �޼��带 �����ϴ� Ŭ�����Դϴ�.
	/// - GetAllActorsWithTag(WorldContextObject, Tag, OutActors) : Tag �� ���� ���͸� ���忡�� ã��
	///   OutActors �� �����մϴ�.

	// ���͸� ã�� ���ߴٸ�
	if (findActors.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("GamePlayerController.cpp :: %d LINE :: findActors elem is 0!"), 
			__LINE__);
		return;
	}

	SetViewTargetWithBlend(findActors[0]);
	/// - SetViewTargetWithBlend(NewViewTarget) 
	/// - �� Ÿ���� NewViewTarget ���� �����մϴ�.
}


void AGamePlayerController::RotateController()
{
	SetControlRotation(
		FRotator(0.0f, PlayerCharacter->GetHorizontalInputValue() * 90.0f, 0.0f));
}
