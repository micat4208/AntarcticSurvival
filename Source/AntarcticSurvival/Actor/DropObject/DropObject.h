#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/Actor.h"

#include "Enum/DropObjectType.h"

#include "DropObject.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API ADropObject final : 
	public AActor
{
	GENERATED_BODY()

private :
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* DropObjectMesh;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class URotatingMovementComponent* RotatingMovement;


private :
	// �������� �ӷ��� ��Ÿ���ϴ�.
	float FallDownSpeed;

	// �÷��̾�� ���� ����� / ȸ���� ü���� ��Ÿ���ϴ�.
	float ChangeHungryValue;

	// ������Ʈ�� Ÿ���� ��Ÿ���ϴ�.
	EDropObjectType DropObjectType;

public:	
	ADropObject();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private :
	// �������� �������� �����մϴ�.
	void FallDown(float dt);

public :
	// DropObject �� �ʱ�ȭ�մϴ�.
	void InitializeDropObject(float fallDownSpeed, 
		struct FDropObjectInfo * dropObjInfo);

private :
	UFUNCTION() // Dynamic Delegate �� ���ε��� �޼����̹Ƿ� �ۼ��մϴ�.
	void AddDamage(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);
	/// - OverlappedComponent : ��ģ �ڽ��� ������Ʈ�� ���޵˴ϴ�.
	/// - OtherActor : ��ģ ��� ���Ͱ� ���޵˴ϴ�.
	/// - OtherComp : ��ģ ��� ������Ʈ�� ���޵˴ϴ�.
	/// - OtherBodyIndex : bMultibodyOverlap �� true �� ���
	///   ���� �ø����� ������ ��� �ø������� �����ϱ� ���ѹ�ȣ
	/// - bFromSweep : ���Ͱ� �̵��� �� Sweep �̺�Ʈ�� �߻���Ű���� �Ͽ� �߻���
	///   �߻��� �̺�Ʈ������ ��Ÿ���ϴ�.
	/// - SweepResult : Sweep �̺�Ʈ �߻� �� 
	///   �ڼ��� ����� ��� �ִ� �����Ͱ� ���޵˴ϴ�.

};
