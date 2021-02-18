#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API AGamePlayerController : 
	public APlayerController
{
	GENERATED_BODY()

protected :
	virtual void BeginPlay() override;

	// ���� ���ǵ� �� ȣ��Ǵ� �޼���
	virtual void OnPossess(APawn* aPawn) override;

private :
	// ī�޶� �並 �����մϴ�.
	void SetCameraView();



	
};
