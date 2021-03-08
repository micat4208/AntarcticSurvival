#include "TitleWidget.h"


void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 애니메이션 재생
	PlayAnimation(Anim_FloatingLogo, 0.0f, 0);
}