// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "F4AttributeSet.generated.h"

// Uses macros from AttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) 
#define	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) 
#define	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) 
#define	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) 
#define	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class FOREST4GUARDIANS_API UF4AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UF4AttributeSet();

	// �� HP���� �ٸ� �÷��̾�� �ѷ��ִ� �뵵(?)
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// ���� ������ Attribute Mecro�� ����Ͽ� ü�� ����.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
		FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UF4AttributeSet, Health);

	UFUNCTION()
		virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	// ���� ������ Attribute Mecro�� ����Ͽ� ���ݷ� ����.
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_AttackPower)
		FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UF4AttributeSet, AttackPower);

	UFUNCTION()
		virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);

};
