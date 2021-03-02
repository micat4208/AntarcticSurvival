#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

// 해당 클래스를 추상 클래스로 설정합니다.
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
	// 폰에 빙의될 때 호출되는 메서드
	virtual void OnPossess(APawn* aPawn) override;

protected :
	// 위젯을 띄웁니다.
	/// - widgetClass : 띄울 위젯의 UClass 를 전달합니다.
	class UUserWidget* FloatingWidget(TSubclassOf<class UUserWidget> widgetClass);

private :
	// 카메라 뷰를 설정합니다.
	void SetCameraView();

public :
	// 띄운 위젯 객체를 얻습니다.
	FORCEINLINE class UUserWidget* GetWidget() const
	{ return Widget; }



};
