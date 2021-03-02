#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

// �ش� Ŭ������ �߻� Ŭ������ �����մϴ�.
UCLASS(Abstract)
class ANTARCTICSURVIVAL_API ABasePlayerController : 
	public APlayerController
{
	GENERATED_BODY()
	
private :
	UPROPERTY()
	class UUserWidget* Widget;

public :
	ABasePlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected :
	// ���� ���ǵ� �� ȣ��Ǵ� �޼���
	virtual void OnPossess(APawn* aPawn) override;

protected :
	// ������ ���ϴ�.
	/// - widgetClass : ��� ������ UClass �� �����մϴ�.
	class UUserWidget* FloatingWidget(TSubclassOf<class UUserWidget> widgetClass);

private :
	// ī�޶� �並 �����մϴ�.
	void SetCameraView();

public :
	// ��� ���� ��ü�� ����ϴ�.
	FORCEINLINE class UUserWidget* GetWidget() const
	{ return Widget; }



};
