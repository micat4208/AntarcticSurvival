#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"
/// - UHT �� ���� �ڵ����� �����Ǵ� �ΰ� ����
/// - ����� ���� �ϴܿ� �ۼ��ؾ� �մϴ�.

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
