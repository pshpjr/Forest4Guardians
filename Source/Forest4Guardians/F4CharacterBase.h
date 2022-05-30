// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include <GameplayEffectTypes.h>
#include "F4CharacterBase.generated.h"

UCLASS()
class FOREST4GUARDIANS_API AF4CharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
		// 다른 구성요소들이 이곳에 이미 선언되어 있기 때문에 어빌리티시스템 컴포턴트를 같이 사용할 수 있도록 추가만 해주면 됨.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UF4AbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UF4AttributeSet* Attributes;

public:
	// Sets default values for this character's properties
	AF4CharacterBase();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void InitializedAttributes();
	virtual void GiveAbilities();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;


	// Effect that initializes our default attributes
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
		TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	// 플레이어에게 제공할 기본적인 능력
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GAS")
		TArray<TSubclassOf<class UF4GameplayAbility>> DefaultAbilities;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
