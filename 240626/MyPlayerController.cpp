// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "UObject/ConstructorHelpers.h" // FObjectFinder 사용하기 위한 인클루드
#include "Kismet/KismetSystemLibrary.h"
#include "EnhancedInput/Public/InputAction.h"
#include "EnhancedInput/Public/InputMappingContext.h"

AMyPlayerController::AMyPlayerController()
{
	static ConstructorHelpers::FObjectFinder<UInputAction> IA_Move_OBJ(TEXT("/Game/PaperAssets/Assets/Paper2D/Input/Actions/IA_Move"));

	IA_Move = IA_Move_OBJ.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> IA_Attack_OBJ(TEXT("/Game/PaperAssets/Assets/Paper2D/Input/Actions/IA_Attack"));

	IA_Attack = IA_Attack_OBJ.Object;

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC_SideScrollers_OBJ(TEXT("/Game/PaperAssets/Assets/Paper2D/Input/IMC_SideScrollers"));
		
	IMC_SideScrollers = IMC_SideScrollers_OBJ.Object;
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay(); //override 되어서 Super 써서 

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMC_SideScrollers.Get(),1);
	}

}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(IA_Move.Get(), ETriggerEvent::Triggered, this, &AMyPlayerController::Move);
		EnhancedInputComponent->BindAction(IA_Attack.Get(), ETriggerEvent::Triggered, this, &AMyPlayerController::Attack);
	}
}

void AMyPlayerController::Move(const FInputActionValue& Value)
{
	/*if (APawn* ControllerdPawn = GetPawn())
		{
			FVector2D MovementPawn = GetPawn();

	ControllerdPawn->AddMovementInput(FVector(AddMovementInput.x, 0, 0f, 0, 0f));
		}*/

	if (APawn* ControllerdPawn = GetPawn())
	{
		FVector2D MovementPawn = GetPawn();

		ControllerdPawn->AddMovementInput(FVector(MovementInput.x , 0, 0f, 0, 0f));
	}

//	const FVector2D MovementVector = Value.Get<FVector2D>();
//
//	UKismetSystemLibrary::PrintString(this, TEXT("ABF_Hello"));
//
//	if (APawn* ControlledPawn = GetPawn())
//	{
//		ControlledPawn->AddMovementInput(FVector(MovementVector.X * 15.0f, 0.0f, 0.0f));
//	}
//}

void AMyPlayerController::Attack(const FInputActionValue& Value)
{
}
