#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterMovementHelperComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANTARCTICSURVIVAL_API UCharacterMovementHelperComponent : public UActorComponent
{
	GENERATED_BODY()

private :
	// ����� PlayerCharacter ��ü�� ��Ÿ���ϴ�.
	UPROPERTY() // PlayerCharacter �� �⺻ ��(nullptr)�� ����ޱ� ���Ͽ� �ۼ��մϴ�.
	class APlayerCharacter* PlayerCharacter;

public:	
	UCharacterMovementHelperComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private :
	// �¿� �̵��� �����մϴ�.
	void HorizontalMovement();

		
};
