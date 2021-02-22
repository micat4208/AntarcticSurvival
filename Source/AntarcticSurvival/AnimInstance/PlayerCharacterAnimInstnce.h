#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerCharacterAnimInstnce.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API UPlayerCharacterAnimInstnce : 
	public UAnimInstance
{
	GENERATED_BODY()

protected :
	// ���� ĳ���� �ӷ�
	UPROPERTY(BlueprintReadOnly)
	float VelocityLength;
	/// - BlueprintReadOnly : �������Ʈ Ŭ�������� �б� �������� ������ ��Ÿ���ϴ�.
	/// - BlueprintReadWrite : �������Ʈ Ŭ�������� �б� ���Ⱑ ��� ������ Ÿ������ ��Ÿ���ϴ�.

public :
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	
};
