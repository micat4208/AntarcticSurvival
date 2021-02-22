#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API AGamePlayerController : 
	public APlayerController
{
	GENERATED_BODY()

private :
	// 조종당하는 PlayerCharacter Pawn 을 나타냅니다.
	UPROPERTY()
	class APlayerCharacter* PlayerCharacter;

protected :
	virtual void BeginPlay() override;

	// 폰에 빙의될 때 호출되는 메서드
	virtual void OnPossess(APawn* aPawn) override;

public :
	virtual void Tick(float DeltaTime) override;

private :
	// 카메라 뷰를 설정합니다.
	void SetCameraView();

public :
	void RotateController();



	
};
