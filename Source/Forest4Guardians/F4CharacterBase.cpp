// Fill out your copyright notice in the Description page of Project Settings.


#include "F4CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "F4AbilitySystemComponent.h"
#include "F4AttributeSet.h"
#include "F4GameplayAbility.h"
#include <GameplayEffectTypes.h>


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
	// 어빌리티 

	AbilitySystemComponent = CreateDefaultSubobject<UF4AbilitySystemComponent>("AbilitySystemComp");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	Attributes = CreateDefaultSubobject<UF4AttributeSet>("Attributes");
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


class UAbilitySystemComponent* AF4CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AF4CharacterBase::InitializedAttributes()
{
	if (AbilitySystemComponent && DefaultAttributeEffect)
	{
		// 컨텍스트 핸들이란?
		FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(this);

		FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContext);

		if (SpecHandle.IsValid())
		{
			FActiveGameplayEffectHandle GEHandle = AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
		}
	}
}

void AF4CharacterBase::GiveAbilities()
{
	if (HasAuthority() && AbilitySystemComponent)
	{
		for (TSubclassOf<UF4GameplayAbility>& StartupAbility : DefaultAbilities)
		{
			AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(StartupAbility, 1, static_cast<int32>(StartupAbility.GetDefaultObject()->AbilityInputID), this));
		}
	}
}

void AF4CharacterBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Server GAS init
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitializedAttributes();
	GiveAbilities();
}

void AF4CharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	InitializedAttributes();

	if (AbilitySystemComponent && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds("Confirm", "Cancel", "EF4AbilityInputID", static_cast<int32>(EF4AbilityInputID::Confirm), static_cast<int32>(EF4AbilityInputID::Cancel));
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

// Called to bind functionality to input
void AF4CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (AbilitySystemComponent && InputComponent)
	{
		const FGameplayAbilityInputBinds Binds("Confirm", "Cancel", "EF4AbilityInputID", static_cast<int32>(EF4AbilityInputID::Confirm), static_cast<int32>(EF4AbilityInputID::Cancel));
		AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

