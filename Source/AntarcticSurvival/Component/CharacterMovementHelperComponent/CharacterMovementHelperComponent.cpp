#include "CharacterMovementHelperComponent.h"

#include "Actor/PlayerCharacter/PlayerCharacter.h"
//#include "GameFramework/CharacterMovementComponent.h"

UCharacterMovementHelperComponent::UCharacterMovementHelperComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

void UCharacterMovementHelperComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCharacterMovementHelperComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// �¿� �̵��� ��ŵ�ϴ�.
	HorizontalMovement();
}

void UCharacterMovementHelperComponent::HorizontalMovement()
{
	// PlayerCharacter �� nullptr ���
	if (!IsValid(PlayerCharacter))
	{
		// PlayerCharacter ���͸� ����ϴ�.
		PlayerCharacter = Cast<APlayerCharacter>(GetOwner());
		/// - Cast<T>(instance) : instance �� T �������� ĳ�����մϴ�.
		///   ĳ���ÿ� ������ ��� nullptr �� ��ȯ�մϴ�.
		/// - GetOwner() : ������Ʈ�� �����ϴ� Actor �� ��ȯ�մϴ�.
	}

	// �̵��� ������ �����մϴ�.
	FVector moveDirection = PlayerCharacter->GetHorizontalInputValue() *
		FVector::RightVector;

	// ĳ���͸� �̵���ŵ�ϴ�.
	PlayerCharacter->AddMovementInput(moveDirection);

}

