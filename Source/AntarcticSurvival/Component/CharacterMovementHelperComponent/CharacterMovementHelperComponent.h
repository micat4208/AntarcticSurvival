#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterMovementHelperComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANTARCTICSURVIVAL_API UCharacterMovementHelperComponent : public UActorComponent
{
	GENERATED_BODY()

private :
	// 사용할 PlayerCharacter 객체를 나타냅니다.
	UPROPERTY() // PlayerCharacter 의 기본 값(nullptr)을 보장받기 위하여 작성합니다.
	class APlayerCharacter* PlayerCharacter;

public:	
	UCharacterMovementHelperComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private :
	// 좌우 이동을 구현합니다.
	void HorizontalMovement();

		
};
