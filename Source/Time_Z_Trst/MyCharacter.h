
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Math/UnrealMathUtility.h"
#include "MyCharacter.generated.h"

UCLASS()
class TIME_Z_TRST_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AMyCharacter();

	UPROPERTY(EditDefaultsOnly, Category="CharacterSettings")
	float health = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSettings")
	float hanger = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSettings")
	float thurst = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSettings")
	bool bIsDead;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSettings")
	float Stamina = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSettings")
	float CurrentStamina = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSettings")
	float MinusStamina = 0.5f;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSettings")
	float PlusStamina = 1.0f;
	UPROPERTY(EditDefaultsOnly, Category = "CharacterSettings")
	bool bIsSprint;

	
	float GetHealth();
	float GetHanger();
	float GetThurst();

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumpAnimation")
	UAnimMontage* JumpAnimation;


	virtual void SetupPlayerInputComponent(class UInputComponent* MyPlayerInput) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Jump();
	void StopJump();
	void DecreaseStamina();
	void IncreaseStamina();
	void Sprint();
	void StopSprint();

	virtual void Tick(float DeltaTime) override;
};