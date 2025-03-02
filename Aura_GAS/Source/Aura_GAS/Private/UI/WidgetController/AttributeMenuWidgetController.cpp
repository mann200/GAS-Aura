// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "Player/AuraPlayerState.h"


void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	check(AttributeInfo);
	for (auto& Info : GetAuraAS()->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Info.Value()).AddLambda(
	[this,Info](const FOnAttributeChangeData& Data)
		{
			BroadcastAttributeInfo(Info.Key,Info.Value());
		});
	}
	
	GetAuraPS()->OnAttributePointsChangedDelegate.AddLambda(
		[this](int32 Points)
		{
			AttributePointsChangedDelegate.Broadcast(Points);
		});
	
}

void UAttributeMenuWidgetController::BroadcastInitialValue()
{
	check(AttributeInfo);
	//TFieldIterator<UFunction> AttributesProperty(UAuraAttributeSet::StaticClass())
	for (auto& Info : GetAuraAS()->TagsToAttributes)
	{
		BroadcastAttributeInfo(Info.Key,Info.Value());
	}
	
	AttributePointsChangedDelegate.Broadcast(GetAuraPS()->GetAttributePoints());
}

void UAttributeMenuWidgetController::UpgradeAttribute(const FGameplayTag& AttributeTag)
{
	GetAuraASC()->UpgradeAttribute(AttributeTag);
}

void UAttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag,const FGameplayAttribute& Attribute)  const
{
	FAuraAttributeInfo AttInfo = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
	AttInfo.AttributeValue = Attribute.GetNumericValue(AttributeSet);
	AttributeInfoDelegate.Broadcast(AttInfo);
}
