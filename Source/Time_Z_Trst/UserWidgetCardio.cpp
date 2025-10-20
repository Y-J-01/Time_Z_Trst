// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetCardio.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"

float UUserWidgetCardio::GetCharacterCardio()
{
	AMyCharacter* OurPlayer = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	float GetStamina = OurPlayer->Stamina / 100.f;

	return GetStamina;
}
