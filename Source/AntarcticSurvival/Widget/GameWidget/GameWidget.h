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
	// GameWidget Instance �� �ʱ�ȭ�ϴ� �޼���
	void InitializeGameWidget(class ABasePlayerController* playerController);

private :
	void SetGameOverVisibility(bool bVisible);

	// ����� ���¸� ��Ÿ���� �̹����� �¿�� �̵���ŵ�ϴ�.
	void MoveHungryImage();

	// ���� �ؽ�Ʈ�� �����մϴ�.
	void UpdateScoreText();

};