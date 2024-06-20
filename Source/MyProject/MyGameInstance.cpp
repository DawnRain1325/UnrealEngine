// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/Actor.h"

UMyGameInstance::UMyGameInstance() {
	//엑터 블루프린터
	static ConstructorHelpers::FClassFinder<AActor> ActorBPClass(TEXT("/Game/UI/BP_MyActor"));
	if (ActorBPClass.Succeeded())
	{
		BP_MyActorClass = ActorBPClass.Class;

		UE_LOG(LogTemp, Warning, TEXT("D:/LWT/MyProject/Content/UI/BP_MyActor.uasset"));
	}
	
	UE_LOG(LogTemp, Warning, TEXT("D:/LWT/MyProject/Content/UI/BP_MyActor.uasset"));
}

void UMyGameInstance::Init()
{
	Super::Init();
	ControlBP_MyActor();
}

void UMyGameInstance::ControlBP_MyActor()
{
	if (BP_MyActorClass != nullptr && GetWorld() != nullptr)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = nullptr;
		SpawnParams.Instigator = nullptr;

		AActor* spawnActor = GetWorld()->SpawnActor<AActor>(BP_MyActorClass, FVector::ZeroVector,
			FRotator::ZeroRotator, SpawnParams);

		if (spawnActor)
		{
			UE_LOG(LogTemp , Warning , TEXT("Success_Create"))
		}
			

	}
}
