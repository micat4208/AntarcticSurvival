#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameWidget.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API UGameWidget final : 
	public UUserWidget
{
	GENERATED_BODY()

private :
	class AGamePlayerController* PlayerController;

private :
	UPROPERTY(meta = (BindWidget))
	class UTextBlock * Text_Score;

	UPROPERTY(meta = (BindWidget))
	class UImage* Image_HungryGauge;

	UPROPERTY(meta = (BindWidget))
	class UImage * Image_CurrentGauge;

	UPROPERTY(meta = (BindWidget))
	class UOverlay * Overlay_GameOver;

protected :
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
public :
	// GameWidget Instance 를 초기화하는 메서드
	void InitializeGameWidget(class ABasePlayerController* playerController);

	void SetGameOverVisibility(bool bVisible, bool bStartTimer = false);

private :
	// 배고픔 상태를 나타내는 이미지를 좌우로 이동시킵니다.
	void MoveHungryImage();

	// 점수 텍스트를 갱신합니다.
	void UpdateScoreText();

	void ChangeToTitleMap();

};
