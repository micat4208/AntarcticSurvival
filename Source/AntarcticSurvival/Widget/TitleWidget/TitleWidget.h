// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AntarcticSurvival.h"
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

	UPROPERTY(meta = (BindWidget))
	class UButton * Button_GameStart;

	UPROPERTY(meta = (BindWidget))
	class UButton * Button_Quit;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock * Text_Date;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock * Text_Score;

protected :
	virtual void NativeConstruct() override;

private :
	void UpdateBestScore();

private :
	UFUNCTION()
	void OnGameStartButtonClicked();

	UFUNCTION()
	void OnQuitButtonClicked();



};
