// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstnce.h"



void UPlayerCharacterAnimInstnce::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// 해당 메서드는 에디터에서도 호출되기 때문에 TryGetPawnOwner() 이 nullptr 를 반환한다면
	// 실행되지 않도록 합니다.
	/// - Editer -> TryGetPawnOwner() 는 nullptr 를 반환함.
	if (!IsValid(TryGetPawnOwner())) return;

	// 벡터의 길이를 VelocityLength 에 저장합니다.
	VelocityLength = TryGetPawnOwner()->GetVelocity().Size();
}