// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bIsDead = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	Camera->SetupAttachment(SpringArm);

	SpringArm->bUsePawnControlRotation = true;
	Camera->bUsePawnControlRotation = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

float AMyCharacter::GetHealth()
{
	if (health <= 0.0f) {
		bIsDead = true;

		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	return bIsDead;
}

float AMyCharacter::GetHanger()
{
	return hanger;
}

float AMyCharacter::GetThurst()
{
	return thurst;
}



void AMyCharacter::SetupPlayerInputComponent(UInputComponent* MyPlayerInput)
{
	Super::SetupPlayerInputComponent(MyPlayerInput);

	MyPlayerInput->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	MyPlayerInput->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	MyPlayerInput->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	MyPlayerInput->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);

	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &AMyCharacter::Jump);
	MyPlayerInput->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);

	MyPlayerInput->BindAction("Sprint", IE_Pressed, this, &AMyCharacter::Sprint);
	MyPlayerInput->BindAction("Sprint", IE_Released, this, &AMyCharacter::StopSprint);
	
}

void AMyCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AMyCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AMyCharacter::Jump()
{
	bPressedJump = true;
	if (JumpAnimation)
	{
		PlayAnimMontage(JumpAnimation, 1.0, NAME_None);
	}
}

void AMyCharacter::StopJump()
{
	bPressedJump = false;
}

void AMyCharacter::DecreaseStamina()
{
	CurrentStamina = Stamina - MinusStamina;
	Stamina = CurrentStamina;

	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Stamina Decrease %f"), Stamina));
}

void AMyCharacter::IncreaseStamina()
{
	if (bIsSprint == false)
	{
		CurrentStamina = Stamina + PlusStamina;
		Stamina = CurrentStamina;

		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Stamina Inrease %f"), Stamina));
	}
}
void AMyCharacter::Sprint()
{
	bIsSprint = true;
	GetCharacterMovement()->MaxWalkSpeed = 1200.0f;

	DecreaseStamina();
}

void AMyCharacter::StopSprint()
{
	bIsSprint = false;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;

	IncreaseStamina();
}

void AMyCharacter::Tick(float DeltaTime)
{
	if (bIsSprint == true && Stamina != 0.f)
	{
		DecreaseStamina();
	}
	else
	{
		if (bIsSprint == false && Stamina != 100.f)
		{
			IncreaseStamina();
		}
	}

	if (FMath::IsNearlyZero(Stamina))
	{
		StopSprint();
	}
}
