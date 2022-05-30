// Fill out your copyright notice in the Description page of Project Settings.


#include "F4AttributeSet.h"
#include "Net/UnrealNetwork.h"

UF4AttributeSet::UF4AttributeSet()
{

}

void UF4AttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// REPNOTIFY_Always �� ����ϴ� ������ ���� ����� �� ȣ��Ǵ� ���� �ƴ� �׻� ȣ��Ǳ⸦ ���ϹǷ�.
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
