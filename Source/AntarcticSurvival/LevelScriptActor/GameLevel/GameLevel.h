#pragma once

#include "AntarcticSurvival.h"
#include "Engine/LevelScriptActor.h"
#include "GameLevel.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API AGameLevel : public ALevelScriptActor
{
	GENERATED_BODY()

private :
	class USoundWave* S_Game;

public :
	AGameLevel();

protected :
	virtual void BeginPlay() override;
	
};
