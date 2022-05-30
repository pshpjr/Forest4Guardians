// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "Forest4Guardians.h"
#include "F4GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class FOREST4GUARDIANS_API UF4GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UF4GameplayAbility();

	// Abilites with this set will �ڵ������� Ȱ��ȭ�ɰ��̴�. Ű �Է� ��ǲ�� ������ ��.
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
		EF4AbilityInputID AbilityInputID = EF4AbilityInputID::None;
};
