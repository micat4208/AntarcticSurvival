#pragma once


#include "Actor/PlayerController/BasePlayerController.h"
#include "GamePlayerController.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API AGamePlayerController : 
	public ABasePlayerController
{
	GENERATED_BODY()

private :
	// BP_Game Widget Ŭ������ ��Ÿ���ϴ�.
	TSubclassOf<class UUserWidget> BP_Game;

private :
	// �������ϴ� PlayerCharacter Pawn �� ��Ÿ���ϴ�.
	UPROPERTY()
	class APlayerCharacter* PlayerCharacter;

public :
	AGamePlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected :
	virtual void BeginPlay() override;

	// ���� ���ǵ� �� ȣ��Ǵ� �޼���
	virtual void OnPossess(APawn* aPawn) override;

public :
	virtual void Tick(float DeltaTime) override;


public :
	void RotateController();



	
};
