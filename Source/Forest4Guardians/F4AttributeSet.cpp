// Fill out your copyright notice in the Description page of Project Settings.


#include "F4AttributeSet.h"
#include "Net/UnrealNetwork.h"

UF4AttributeSet::UF4AttributeSet()
{

}

void UF4AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// REPNOTIFY_Always 를 사용하는 이유는 값이 변경될 때 호출되는 것이 아닌 항상 호출되기를 원하므로.
	DOREPLIFETIME_CONDITION_NOTIFY(UF4AttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UF4AttributeSet, AttackPower, COND_None, REPNOTIFY_Always);
}

void UF4AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UF4AttributeSet, Health, OldHealth);
}

void UF4AttributeSet::OnRep_AttackPower(const FGameplayAttributeData & OldAttackPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UF4AttributeSet, AttackPower, OldAttackPower);
}
