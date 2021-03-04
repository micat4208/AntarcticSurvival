// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Serialization/JsonWriter.h"
#include "JsonObjectConverter.h"

#include "ASGameInst.generated.h"

#ifndef GAME_INST_DEF
#define GAME_INST_DEF
#define GameInst() (Cast<UASGameInst>(GetGameInstance()))
#endif

UCLASS()
class ANTARCTICSURVIVAL_API UASGameInst final : 
	public UGameInstance
{
	GENERATED_BODY()
	
private :
	// 현재 점수를 나타냅니다.
	UPROPERTY()
	float CurrentScore;

public :
	// 점수를 증가시킵니다.
	void AddScore(float addScore);

public :
	FORCEINLINE float GetCurrentScore() const
	{ return CurrentScore; }


	template<typename T>
	void SaveJson(FString fileName, T& saveData, FString fieldName = FString(TEXT("default")))
	{
		FString folderPath = FPaths::GameDir() + TEXT("/Content/Resources/Json");

		// 만약 경로가 없다면 경로 생성
		if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*folderPath))
			FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*folderPath);

		FString serializedData;
		FJsonObjectConverter::UStructToJsonObjectString(saveData, serializedData);

		FString jsonStr;
		auto jsonObj = TJsonWriterFactory<>::Create(&jsonStr);
		jsonObj->WriteObjectStart();

		jsonObj->WriteValue(fieldName, serializedData);

		jsonObj->WriteObjectEnd();
		jsonObj->Close();

		folderPath += FString(TEXT("/")) + fileName + FString(TEXT(".json"));

		FFileHelper::SaveStringToFile(*jsonStr, *folderPath);
	}
};
