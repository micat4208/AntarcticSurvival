// Fill out your copyright notice in the Description page of Project Settings.


#include "ASGameInst.h"

void UASGameInst::AddScore(float addScore)
{
	CurrentScore += addScore;

	CurrentScore = (CurrentScore < 0.0f) ? 0.0f : CurrentScore;
	//if (CurrentScore < 0.0f) CurrentScore = 0.0f;


}

