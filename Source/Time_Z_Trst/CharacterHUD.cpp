// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"
#include "Blueprint/UserWidget.h"

ACharacterHUD::ACharacterHUD() : Super()
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBPCardio(TEXT("/Game/World/Map/Widgets/WBP_Cardio"));

	MainHUD = WBPCardio.Class;


}

void ACharacterHUD::BeginPlay()
{

	Super::BeginPlay();

	UUserWidget* CharacterWidget = CreateWidget(GetWorld(), MainHUD);
	CharacterWidget->AddToViewport();

}
