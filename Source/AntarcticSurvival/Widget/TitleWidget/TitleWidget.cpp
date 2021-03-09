#include "TitleWidget.h"

#include "Single/GameInstance/ASGameInst.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// �ִϸ��̼� ���
	PlayAnimation(Anim_FloatingLogo, 0.0f, 0);

	Button_GameStart->OnClicked.AddDynamic(this, &UTitleWidget::OnGameStartButtonClicked);
	Button_Quit->OnClicked.AddDynamic(this, &UTitleWidget::OnQuitButtonClicked);

	UpdateBestScore();
}

void UTitleWidget::UpdateBestScore()
{
	// GameInstance
	auto gameInst = Cast<UASGameInst>(GetWorld()->GetGameInstance());

	// �ְ� ���� ������ �ε�
	FSaveData loadedData;
	// �ְ� ���� ������ �ε忡 �����ߴٸ�
	if (gameInst->LoadJson(TEXT("BestData"), loadedData))
	{
		// ����� ���� ��¥ / �ð� ����
		Text_Date->SetText(loadedData.GetDateString());

		// �ְ� ���� �ؽ�Ʈ ���� ����
		Text_Score->SetText(loadedData.GetScoreText());
	}

}

void UTitleWidget::OnGameStartButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("GameMap"));
}

void UTitleWidget::OnQuitButtonClicked()
{
	// ������ �����մϴ�.
	UKismetSystemLibrary::QuitGame(
		GetWorld(),
		UGameplayStatics::GetPlayerController(GetWorld(), 0),
		EQuitPreference::Quit,
		false);
}
