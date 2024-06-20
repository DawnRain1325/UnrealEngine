// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h" // Uuserwidget 헤더 파일 포함



AMyPlayerController::AMyPlayerController()
{
	//위젯 플루프린터를 찾기 위한 클래스 찾기 도구
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClassFinder(TEXT("/Game/UI/WBP_Intro"));
	//로그출력
	UE_LOG(LogTemp, Warning, TEXT("WidgetBlueprint'/Game/UI/WBP_Intro.WBP_Intro'"));
	//성공여부확인
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
