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
	// 떨어지는 속력을 나타냅니다.
	float FallDownSpeed;

public:	
	ADropObject();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

private :
	// 떨어지는 움직임을 수행합니다.
	void FallDown(float dt);

public :
	// DropObject 를 초기화합니다.
	void InitializeDropObject(float fallDownSpeed, 
		struct FDropObjectInfo * dropObjInfo);

};
