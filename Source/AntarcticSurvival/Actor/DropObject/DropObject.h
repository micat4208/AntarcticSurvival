#pragma once

#include "AntarcticSurvival.h"
#include "GameFramework/Actor.h"
#include "DropObject.generated.h"

UCLASS()
class ANTARCTICSURVIVAL_API ADropObject final : 
	public AActor
{
	GENERATED_BODY()

private :
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* DropObjectMesh;

private :
	// �������� �ӷ��� ��Ÿ���ϴ�.
	float FallDownSpeed;

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

};
