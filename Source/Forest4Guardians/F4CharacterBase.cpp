// Fill out your copyright notice in the Description page of Project Settings.


#include "F4CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
AF4CharacterBase::AF4CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	UCharacterMovementComponent* const MovementComponent = GetCharacterMovement();
	if (MovementComponent)
	{
		MovementComponent->bOrientRotationToMovement = true;

	}
}

// Called when the game starts or when spawned
void AF4CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AF4CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AF4CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

