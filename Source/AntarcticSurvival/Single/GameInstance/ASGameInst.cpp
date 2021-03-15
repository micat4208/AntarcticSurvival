#include "ASGameInst.h"

void UASGameInst::Init()
{
	Super::Init();

	TryUpdateBestScore();
}

void UASGameInst::AddScore(float addScore)
{
	if (bIsGameOver) return;

	CurrentScore += addScore;

	CurrentScore = (CurrentScore < 0.0f) ? 0.0f : CurrentScore;
	//if (CurrentScore < 0.0f) CurrentScore = 0.0f;
}

void UASGameInst::TryUpdateBestScore()
{
	FSaveData saveData;
	GetSaveData(saveData);

	if (CurrentScore > saveData.BestScore)
	{
		FSaveData bestData(CurrentScore, FDateTime::Now());
		SaveJson(TEXT("BestData"), bestData);
	}
}

bool UASGameInst::GetSaveData(FSaveData& outSaveData)
{
	// 로드 결과를 저장합니다.
	bool res = LoadJson(TEXT("BestData"), outSaveData);

	return res;
}

