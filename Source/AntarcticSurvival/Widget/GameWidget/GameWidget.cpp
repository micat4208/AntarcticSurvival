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

	// 펭귄 이미지를 좌우로 이동시킵니다.
	MoveHungryImage();
}

void UGameWidget::InitializeGameWidget(ABasePlayerController* playerController)
{
	PlayerController = Cast<AGamePlayerController>(playerController);
}

void UGameWidget::MoveHungryImage()
{
	// 플레이어 캐릭터가 존재하지 않는 경우 메서드 호출 종료
	auto playerCharacter = PlayerController->GetPlayerCharacter();
	if (!IsValid(playerCharacter)) return;

	// Image_HungryGauge 위젯 크기를 얻습니다.
	FVector2D gaugeSize = Cast<UCanvasPanelSlot>(Image_HungryGauge->Slot)->GetSize();

	// Image_CurrentGauge 의 CanvasPanelSlot 을 얻습니다.
	auto currentGaugeSlot = Cast<UCanvasPanelSlot>(Image_CurrentGauge->Slot);

	// 설정할 위치를 계산합니다.
	FVector2D newPosition = currentGaugeSlot->GetPosition();
	newPosition.X = (gaugeSize.X * 0.01f) * playerCharacter->GetHungryValue();

	// Image_CurrentGauge 의 X 위치를 변경합니다.
	currentGaugeSlot->SetPosition(newPosition);
}
