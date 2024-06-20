// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h" // Uuserwidget ��� ���� ����



AMyPlayerController::AMyPlayerController()
{
	//���� �÷������͸� ã�� ���� Ŭ���� ã�� ����
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(TEXT("/Game/UI/WBP_Intro"));
	//�α����
	UE_LOG(LogTemp, Warning, TEXT("WidgetBlueprint'/Game/UI/WBP_Intro.WBP_Intro'"));
	//��������Ȯ��
	if (WidgetClassFinder.Succeeded())
	{
		WidgetClass = WidgetClassFinder.Class;

		UE_LOG(LogTemp, Warning, TEXT("/Content/UI/BP_MyActor.uasset"));
	}
}

void AMyPlayerController::BeginPlay()
{
	if (WidgetClass != nullptr)
	{
		WidgetInstance = CreateWidget<UUserWidget>(this, WidgetClass);
		if (WidgetInstance != nullptr)
		{
		 WidgetInstance->AddToViewport();
		}

	}
}
