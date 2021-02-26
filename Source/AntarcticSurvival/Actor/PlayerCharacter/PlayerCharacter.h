#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"
/// - UHT 에 의해 자동으로 생성되는 부가 파일
/// - 헤더의 제일 하단에 작성해야 합니다.


//DECLARE_DELEGATE(FTestDelegateSignature)

UCLASS()
/// - 해당 클래스가 UObject 임을 선언합니다.
class ANTARCTICSURVIVAL_API APlayerCharacter final : 
	public ACharacter
{
	/// - U : UObject 형태의 클래스에 사용됩니다.
	/// - A : Actor 클래스를 상속받는 클래스에 사용됩니다.
	/// - F : 일반 클래스나 구조체에 사용됩니다.
	/// - I : 인터페이스 클래스에 사용됩니다.
	///       인터페이스 클래스는 U 도 함께 사용됩니다.
	/// - E : 열거 형식에 사용됩니다.

	GENERATED_BODY()
	/// - 항상 클래스 첫 줄에 작성되어야 합니다.

private :
	// 수평 입력 값을 나타냅니다.
	float HorizontalInputValue;

	// 배고픔 입력 수치를 나타냅니다.
	float HungryValue;

protected :
	UPROPERTY(VisibleAnywhere)
	class UCharacterMovementHelperComponent* MovementHelper;
	/// - VisibleAnywhere : 이 필드가 모든 곳에서 표시되도록 합니다.
	/// - EditAnywhere : 이 필드를 모든 곳에서 값을 변경할 수 있도록 합니다.

public:
	//FTestDelegateSignature myTestDelegate;

	APlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	// 프로젝트 세팅 -> 입력에 매핑한 키 입력 이벤트를 폰에 등록합니다.
	/// - UInputComponent : 액터에 입력 이벤트를 등록하는 기능을 제공하는 컴포넌트입니다.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	// A, D, <, > 키에 바인딩 시킬 메서드입니다.
	void InputHorizontal(float axis);

public :
	// HorizontalInputValue 값을 반환합니다.
	FORCEINLINE float GetHorizontalInputValue() const
	{ return HorizontalInputValue; }

private :
	UFUNCTION()
	void OnHit(
		AActor* DamagedActor, 
		float Damage, 
		const class UDamageType* DamageType, 
		class AController* InstigatedBy, 
		AActor* DamageCauser);

};
