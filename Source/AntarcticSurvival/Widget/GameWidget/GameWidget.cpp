#include "GameWidget.h"

#include "Actor/PlayerController/GamePlayerController.h"
#include "Actor/PlayerCharacter/PlayerCharacter.h"

#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"

void UGameWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UGameWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// ��� �̹����� �¿�� �̵���ŵ�ϴ�.
	MoveHungryImage();
}

void UGameWidget::InitializeGameWidget(ABasePlayerController* playerController)
{
	PlayerController = Cast<AGamePlayerController>(playerController);
}

void UGameWidget::MoveHungryImage()
{
	// �÷��̾� ĳ���Ͱ� �������� �ʴ� ��� �޼��� ȣ�� ����
	auto playerCharacter = PlayerController->GetPlayerCharacter();
	if (!IsValid(playerCharacter)) return;

	// Image_HungryGauge ���� ũ�⸦ ����ϴ�.
	FVector2D gaugeSize = Cast<UCanvasPanelSlot>(Image_HungryGauge->Slot)->GetSize();

	// Image_CurrentGauge �� CanvasPanelSlot �� ����ϴ�.
	auto currentGaugeSlot = Cast<UCanvasPanelSlot>(Image_CurrentGauge->Slot);

	// ������ ��ġ�� ����մϴ�.
	FVector2D newPosition = currentGaugeSlot->GetPosition();
	newPosition.X = (gaugeSize.X * 0.01f) * playerCharacter->GetHungryValue();

	// Image_CurrentGauge �� X ��ġ�� �����մϴ�.
	currentGaugeSlot->SetPosition(newPosition);
}
