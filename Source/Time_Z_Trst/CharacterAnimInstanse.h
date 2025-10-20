// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstanse.generated.h"

/**
 * 
 */
UCLASS()
class TIME_Z_TRST_API UCharacterAnimInstanse : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	APawn* MyCharacter;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Speed;
};
