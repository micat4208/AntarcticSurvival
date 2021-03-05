#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Serialization/JsonWriter.h"
#include "JsonObjectConverter.h"

#include "Struct/SaveData/SaveData.h"

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
	FSaveData SaveData;

	// ���� ������ ��Ÿ���ϴ�.
	UPROPERTY()
	float CurrentScore;

public :
	virtual void Init() override;

public :
	// ������ ������ŵ�ϴ�.
	void AddScore(float addScore);

	// �ְ� ���� ������ �õ��մϴ�.
	void TryUpdateBestScore();

	template<typename T>
	void SaveJson(FString fileName, T& saveData, FString keyName = FString(TEXT("default")))
	{
		// ������ ����� ���� ���
		FString folderPath = FPaths::GameDir() + TEXT("/Content/Resources/Json");
		/// - FPaths : ����, ������ ��� ���� �˻��ϱ� ���� ����� �����ϴ� Ŭ����
		/// - GameDir() : ���� ��θ� ��ȯ�մϴ�.

		// ���� ��ΰ� ���ٸ� ��� ����
		if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*folderPath))
			FPlatformFileManager::Get().GetPlatformFile().CreateDirectory(*folderPath);

		// ������ ������(saveData) �� ���ڿ��� ��ȯ�Ͽ� �����մϴ�.
		FString serializedData;
		FJsonObjectConverter::UStructToJsonObjectString(saveData, serializedData);
		/// - FJsonObjectConverter : Json ��ü�� UStruct ���� ��ȯ�� ���� ����� �����ϴ� Ŭ����
		/// - UStructToJsonObjectString() : UStruct ���� Json ���ڿ��� ��ȯ�մϴ�.

		// Json ���Ͽ� �Է��� ���ڿ� ���� ����
		FString jsonStr;
		auto jsonObj = TJsonWriterFactory<>::Create(&jsonStr);
		/// - TJsonWriter : Json ���� ���⿡ ���� ������ �����ϴ� Ŭ����

		// Json ������Ʈ�� �����մϴ�.
		jsonObj->WriteObjectStart();
		// - Json �� �����ʹ� �߰�ȣ�� ���� �������� �ְ�, Ű : ���� ���� ���еǾ� ����.
		// - �� �� key �� string, �������δ� bool, int, float, string Ÿ������ ����� �� ����.
		// - WriteObjectStart() : �߰�ȣ�� ���� Json ������ ������Ʈ�� ������ ������ �ϸ�,
		//   ������ �߰�ȣ�� �ʿ��ϱ� ������ �ۼ��Ǿ���.
		// - ������ �Է��� �����ٸ� Close() �޼��带 ȣ���Ͽ� Json ������ ���� �˸��� �ȴ�.
		// - Json ������ �����ϱ� ���ؼ� ������ �����͸� ���� string ��ü��, ���� ��θ�
		//   FFileHelper::SaveStringToFile() �޼����� �μ��� �����ϸ� �ȴ�.

		// ������ ����
		jsonObj->WriteValue(keyName, serializedData);

		// Json ������Ʈ �� ����
		jsonObj->WriteObjectEnd();

		// Json ������Ʈ ������ �Է� ��
		jsonObj->Close();

		// ������ ���� ��θ� �����մϴ�.
		folderPath += FString(TEXT("/")) + fileName + FString(TEXT(".json"));

		// ���� ����
		FFileHelper::SaveStringToFile(*jsonStr, *folderPath);
	}

public :
	FORCEINLINE float GetCurrentScore() const
	{ return CurrentScore; }





};
