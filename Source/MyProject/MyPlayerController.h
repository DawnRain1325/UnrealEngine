// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMyPlayerController();
public:
	virtual void BeginPlay() override;

protected:
	//위젯블루프린터
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyUI")
	TSubclassOf<UUserWidget> WidgetClass;

	UUserWidget* WidgetInstance;

};
