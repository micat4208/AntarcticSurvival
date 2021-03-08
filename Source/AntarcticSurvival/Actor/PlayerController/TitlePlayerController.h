#pragma once

#include "Antarcticsurvival.h"
#include "Actor/PlayerController/BasePlayerController.h"
#include "TitlePlayerController.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API ATitlePlayerController final :
	public ABasePlayerController
{
	GENERATED_BODY()


private :
	TSubclassOf<class UTitleWidget> BP_Title;

public :
	ATitlePlayerController();

protected:
	virtual void OnPossess(APawn* aPawn) override;

	
};
