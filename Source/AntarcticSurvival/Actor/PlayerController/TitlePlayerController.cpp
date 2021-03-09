#include "TitlePlayerController.h"

#include "Widget/TitleWidget/TitleWidget.h"

ATitlePlayerController::ATitlePlayerController()
{
	static ConstructorHelpers::FClassFinder<UTitleWidget> BP_TITLE(
		TEXT("WidgetBlueprint'/Game/Blueprints/Widget/BP_Title.BP_Title_C'"));
	if (BP_TITLE.Succeeded()) BP_Title = BP_TITLE.Class;
}

void ATitlePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	FloatingWidget(BP_Title);
	SetInputMode(FInputModeUIOnly());
	bShowMouseCursor = true;
}