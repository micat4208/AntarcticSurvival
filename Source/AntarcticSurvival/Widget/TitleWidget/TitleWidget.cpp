#include "TitleWidget.h"

#include "Single/GameInstance/ASGameInst.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


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
	// GameInstance
	auto gameInst = Cast<UASGameInst>(GetWorld()->GetGameInstance());

	// 최고 점수 데이터 로드
	FSaveData loadedData;
	// 최고 점수 데이터 로드에 성공했다면
	if (gameInst->LoadJson(TEXT("BestData"), loadedData))
	{
		// 기록을 세운 날짜 / 시간 설정
		Text_Date->SetText(loadedData.GetDateString());

		// 최고 점수 텍스트 내용 설정
		Text_Score->SetText(loadedData.GetScoreText());
	}

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
