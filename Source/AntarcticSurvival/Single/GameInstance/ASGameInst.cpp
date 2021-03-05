#include "ASGameInst.h"

void UASGameInst::Init()
{
	Super::Init();

	TryUpdateBestScore();
}

void UASGameInst::AddScore(float addScore)
{
	CurrentScore += addScore;

	CurrentScore = (CurrentScore < 0.0f) ? 0.0f : CurrentScore;
	//if (CurrentScore < 0.0f) CurrentScore = 0.0f;


}

void UASGameInst::TryUpdateBestScore()
{
	FSaveData bestData(CurrentScore, FDateTime::Now());
	SaveJson(TEXT("BestData"), bestData);
}

