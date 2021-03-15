#include "GameLevel.h"

AGameLevel::AGameLevel()
{
	static ConstructorHelpers::FObjectFinder<USoundWave> S_GAME(
		TEXT("SoundWave'/Game/Resources/Audio/game.game'"));
	if (S_GAME.Succeeded()) S_Game = S_GAME.Object;
}


void AGameLevel::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::PlaySound2D(
		GetWorld(),
		S_Game, 0.3f);
}

