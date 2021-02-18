#include "ModeGame.h"

#include "Actor/PlayerCharacter/PlayerCharacter.h"
#include "Actor/PlayerController/GamePlayerController.h"

AModeGame::AModeGame()
{
	/*

	static ConstructorHelpers::FClassFinder<APlayerCharacter> BP_PLAYER_CHARACTER(
		TEXT("Blueprint'/Game/Blueprints/Actor/BP_PlayerCharacter.BP_PlayerCharacter_C'"));
	/// - ConstructorHelpers : �����ڿ��� Resource �� Blueprint Class �� �ҷ����� �۾���
	///   �����ִ� ����� �����ϴ� Ŭ����
	/// - ConstructorHelpers::FClassFinder : UClass �� ������ �� ����ϴ� Ÿ��
	///   - ��� �ڿ� _C �� �ۼ��մϴ�.
	/// - ConstructorHelpers::FObjectFinder : UClass �� ������ �ּ��� ������ �� ����ϴ� Ÿ��

	// �ش� �ּ��� ���������� �ε��ߴٸ�
	if (BP_PLAYER_CHARACTER.Succeeded())
		DefaultPawnClass = BP_PLAYER_CHARACTER.Class;
	/// - ClassName::StaticClass() : ������ C++ Ŭ������ UClass �� ��ȯ�մϴ�.
	// TSubclassOf : UClass Ÿ���� �������� �������ִ� Ŭ�����̸�,
	// UClass �� �������� ���ѽ�ų �� ����մϴ�.

	*/
	DefaultPawnClass = APlayerCharacter::StaticClass();
	PlayerControllerClass = AGamePlayerController::StaticClass();

	//PlayerControllerClass;



}