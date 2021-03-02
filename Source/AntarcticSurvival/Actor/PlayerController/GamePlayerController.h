#pragma once


#include "Actor/PlayerController/BasePlayerController.h"
#include "GamePlayerController.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API AGamePlayerController : 
	public ABasePlayerController
{
	GENERATED_BODY()

private :
	// BP_Game Widget 클래스를 나타냅니다.
	TSubclassOf<class UUserWidget> BP_Game;

private :
	// 조종당하는 PlayerCharacter Pawn 을 나타냅니다.
	UPROPERTY()
	class APlayerCharacter* PlayerCharacter;

public :
	AGamePlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected :
	virtual void BeginPlay() override;

	// 폰에 빙의될 때 호출되는 메서드
	virtual void OnPossess(APawn* aPawn) override;

public :
	virtual void Tick(float DeltaTime) override;


public :
	void RotateController();



	
};
