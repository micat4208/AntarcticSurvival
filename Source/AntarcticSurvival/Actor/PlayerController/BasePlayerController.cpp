#include "BasePlayerController.h"
#include "Blueprint/UserWidget.h"

ABasePlayerController::ABasePlayerController(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{ 
}

void ABasePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	// ī�޶� �� ����
	SetCameraView();
}

UUserWidget* ABasePlayerController::FloatingWidget(TSubclassOf<UUserWidget> widgetClass)
{
	// ���� ��ü ����
	/// - CreateWidget<T>()
	Widget = CreateWidget<UUserWidget>(this, widgetClass);

	// ȭ�鿡 ������ŵ�ϴ�.
	/// - WidgetInstance->AddToViewport()
	Widget->AddToViewport();

	return Widget;
}

void ABasePlayerController::SetCameraView()
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
