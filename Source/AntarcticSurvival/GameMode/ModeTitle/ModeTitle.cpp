#include "ModeTitle.h"

#include "Actor/PlayerController/TitlePlayerController.h"

AModeTitle::AModeTitle()
{
	PlayerControllerClass = ATitlePlayerController::StaticClass();
}
