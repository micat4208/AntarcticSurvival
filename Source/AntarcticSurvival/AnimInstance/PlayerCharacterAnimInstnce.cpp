// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacterAnimInstnce.h"



void UPlayerCharacterAnimInstnce::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// �ش� �޼���� �����Ϳ����� ȣ��Ǳ� ������ TryGetPawnOwner() �� nullptr �� ��ȯ�Ѵٸ�
	// ������� �ʵ��� �մϴ�.
	/// - Editer -> TryGetPawnOwner() �� nullptr �� ��ȯ��.
	if (!IsValid(TryGetPawnOwner())) return;

	// ������ ���̸� VelocityLength �� �����մϴ�.
	VelocityLength = TryGetPawnOwner()->GetVelocity().Size();
}