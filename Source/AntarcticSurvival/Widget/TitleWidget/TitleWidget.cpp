#include "TitleWidget.h"

#include "Components/Button.h"


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
	// �ְ� ���� ������ �ε�

	// �ְ� ���� ������ �ε忡 �����ߴٸ�

		// ����� ���� ��¥ / �ð� ����

		// �ְ� ���� �ؽ�Ʈ ���� ����
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
