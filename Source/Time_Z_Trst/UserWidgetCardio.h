// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetCardio.generated.h"

class MyCharacter;


UCLASS()
class TIME_Z_TRST_API UUserWidgetCardio : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCharacterCardio();


};
