#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"
/// - UHT 에 의해 자동으로 생성되는 부가 파일
/// - 헤더의 제일 하단에 작성해야 합니다.

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

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
