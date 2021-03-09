#include "TitleWidget.h"

#include "Components/Button.h"


void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 애니메이션 재생
	PlayAnimation(Anim_FloatingLogo, 0.0f, 0);

	Button_GameStart->OnClicked.AddDynamic(this, &UTitleWidget::OnGameStartButtonClicked);
	Button_Quit->OnClicked.AddDynamic(this, &UTitleWidget::OnQuitButtonClicked);

	UpdateBestScore();
}

void UTitleWidget::UpdateBestScore()
{
	// 최고 점수 데이터 로드

	// 최고 점수 데이터 로드에 성공했다면

		// 기록을 세운 날짜 / 시간 설정

		// 최고 점수 텍스트 내용 설정
}

void UTitleWidget::OnGameStartButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("GameMap"));
}

void UTitleWidget::OnQuitButtonClicked()
{
	// 게임을 종료합니다.
	UKismetSystemLibrary::QuitGame(
		GetWorld(),
		UGameplayStatics::GetPlayerController(GetWorld(), 0),
		EQuitPreference::Quit,
		false);
}
