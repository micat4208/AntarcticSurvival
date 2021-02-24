#include "DropObject.h"

ADropObject::ADropObject()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADropObject::BeginPlay()
{
	Super::BeginPlay();
}

void ADropObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

