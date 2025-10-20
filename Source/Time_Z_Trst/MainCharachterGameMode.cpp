// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharachterGameMode.h"

AMainCharachterGameMode::AMainCharachterGameMode() : Super()
{
	ConstructorHelpers::FClassFinder<APawn>MainCharacter(TEXT("/Game/World/Map/Blueprint/MyMyCharacter"));

	DefaultPawnClass = MainCharacter.Class;

	HUDClass = ACharacterHUD::StaticClass();
}

