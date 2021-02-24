#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DropObject.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API ADropObject final : 
	public AActor
{
	GENERATED_BODY()
	
public:	
	ADropObject();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
