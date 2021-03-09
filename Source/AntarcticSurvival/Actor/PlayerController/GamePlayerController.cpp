#include "GamePlayerController.h"

#include "Blueprint/UserWidget.h"

#include "Actor/PlayerCharacter/PlayerCharacter.h"

#include "Widget/GameWidget/GameWidget.h"


AGamePlayerController::AGamePlayerController(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UUserWidget> BP_GAME(
		TEXT("WidgetBlueprint'/Game/Blueprints/Widget/BP_Game.BP_Game_C'"));
	if (BP_GAME.Succeeded()) BP_Game = BP_GAME.Class;

}

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

}

void AGamePlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	PlayerCharacter = Cast<APlayerCharacter>(aPawn);
	
	// À§Á¬À» ¶ç¿ì¸ç ¶ç¿î À§Á¬À» ÃÊ±âÈ­ÇÕ´Ï´Ù.
	Cast<UGameWidget>(FloatingWidget(BP_Game))->InitializeGameWidget(this);
	SetInputMode(FInputModeGameOnly());
	bShowMouseCursor = false;
}

void AGamePlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//RotateController();
}

void AGamePlayerController::RotateController()
{
	SetControlRotation(
		FRotator(0.0f, PlayerCharacter->GetHorizontalInputValue() * 90.0f, 0.0f));
}
