#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"
/// - UHT �� ���� �ڵ����� �����Ǵ� �ΰ� ����
/// - ����� ���� �ϴܿ� �ۼ��ؾ� �մϴ�.


//DECLARE_DELEGATE(FTestDelegateSignature)

UCLASS()
/// - �ش� Ŭ������ UObject ���� �����մϴ�.
class ANTARCTICSURVIVAL_API APlayerCharacter final : 
	public ACharacter
{
	/// - U : UObject ������ Ŭ������ ���˴ϴ�.
	/// - A : Actor Ŭ������ ��ӹ޴� Ŭ������ ���˴ϴ�.
	/// - F : �Ϲ� Ŭ������ ����ü�� ���˴ϴ�.
	/// - I : �������̽� Ŭ������ ���˴ϴ�.
	///       �������̽� Ŭ������ U �� �Բ� ���˴ϴ�.
	/// - E : ���� ���Ŀ� ���˴ϴ�.

	GENERATED_BODY()
	/// - �׻� Ŭ���� ù �ٿ� �ۼ��Ǿ�� �մϴ�.

private :
	// ���� �Է� ���� ��Ÿ���ϴ�.
	float HorizontalInputValue;

protected :
	UPROPERTY(VisibleAnywhere)
	class UCharacterMovementHelperComponent* MovementHelper;
	/// - VisibleAnywhere : �� �ʵ尡 ��� ������ ǥ�õǵ��� �մϴ�.
	/// - EditAnywhere : �� �ʵ带 ��� ������ ���� ������ �� �ֵ��� �մϴ�.

public:
	//FTestDelegateSignature myTestDelegate;

	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	// ������Ʈ ���� -> �Է¿� ������ Ű �Է� �̺�Ʈ�� ���� ����մϴ�.
	/// - UInputComponent : ���Ϳ� �Է� �̺�Ʈ�� ����ϴ� ����� �����ϴ� ������Ʈ�Դϴ�.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	// A, D, <, > Ű�� ���ε� ��ų �޼����Դϴ�.
	void InputHorizontal(float axis);

public :
	// HorizontalInputValue ���� ��ȯ�մϴ�.
	FORCEINLINE float GetHorizontalInputValue() const
	{ return HorizontalInputValue; }

};
