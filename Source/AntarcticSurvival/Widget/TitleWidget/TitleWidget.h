// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidget.generated.h"

/**
 * 
 */
UCLASS()
class ANTARCTICSURVIVAL_API UTitleWidget final : 
	public UUserWidget
{
	GENERATED_BODY()
	
private :
	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation * Anim_FloatingLogo;

protected :
	virtual void NativeConstruct() override;


};
