// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstanse.h"

void UCharacterAnimInstanse::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	MyCharacter = TryGetPawnOwner();
}
void UCharacterAnimInstanse::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MyCharacter != nullptr)
	{
		Speed = MyCharacter->GetVelocity().Size();
	}
}