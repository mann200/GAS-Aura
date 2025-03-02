// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AsyncTasks/WaitCooldownChange.h"

#include "AbilitySystemComponent.h"

UWaitCooldownChange* UWaitCooldownChange::WaitForCooldownChange(UAbilitySystemComponent* AbilitySystemComponent,
                                                                const FGameplayTag& InCooldownTag)
{
	UWaitCooldownChange* WaitCooldownChange = NewObject<UWaitCooldownChange>();
	WaitCooldownChange->ASC = AbilitySystemComponent;
	WaitCooldownChange->CooldownTag = InCooldownTag;

	if (!IsValid(AbilitySystemComponent) || !InCooldownTag.IsValid())
	{
		WaitCooldownChange->EndTask();
		return nullptr;
	}

	// To know when a cooldown has ended (Cooldown Tag has been removed)
	AbilitySystemComponent->RegisterGameplayTagEvent(WaitCooldownChange->CooldownTag,EGameplayTagEventType::NewOrRemoved).AddUObject(WaitCooldownChange,&UWaitCooldownChange::CooldownTagChanged);
	// To know when a cooldown effect has been applied
	//AbilitySystemComponent->AbilityActivatedCallbacks.AddUObject(WaitCooldownChange,&UWaitCooldownChange::OnAbilityActivatedCallback);
	//AbilitySystemComponent->OnGameplayEffectAppliedDelegateToSelf.AddUObject(WaitCooldownChange,&UWaitCooldownChange::OnActiveEffectAdded);
	AbilitySystemComponent->OnActiveGameplayEffectAddedDelegateToSelf.AddUObject(WaitCooldownChange,&UWaitCooldownChange::OnActiveEffectAdded);
	
	return WaitCooldownChange;
}

void UWaitCooldownChange::EndTask()
{
	if(!IsValid(ASC)) return;
	ASC->RegisterGameplayTagEvent(CooldownTag,EGameplayTagEventType::NewOrRemoved).RemoveAll(this);
	//ASC->AbilityActivatedCallbacks.RemoveAll(this);
	//ASC->OnActiveGameplayEffectAddedDelegateToSelf.RemoveAll(this);

	SetReadyToDestroy();
	MarkAsGarbage();
}

void UWaitCooldownChange::CooldownTagChanged(const FGameplayTag InCooldownTag, int32 NewCount) const
{
	if (NewCount == 0)
	{
		CooldownEnd.Broadcast(0.f);
	}
}

void UWaitCooldownChange::OnActiveEffectAdded(UAbilitySystemComponent* TargetASC,
	const FGameplayEffectSpec& SpacApplied, FActiveGameplayEffectHandle ActiveEffectHandle) const
{
	FGameplayTagContainer AssetTags;
	SpacApplied.GetAllAssetTags(AssetTags);
	
	if (AssetTags.HasTagExact(CooldownTag))
	{
		const FGameplayEffectQuery GameplayEffectQuery = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(CooldownTag.GetSingleTagContainer());
		TArray<float> TimesRemaining = ASC->GetActiveEffectsTimeRemaining(GameplayEffectQuery);
		if (TimesRemaining.Num() > 0)
		{
			float TimeRemaining = TimesRemaining[0];
			for (int32 i = 0;i < TimesRemaining.Num();i++)
			{
				if (TimesRemaining[i] > TimeRemaining)
				{
					TimeRemaining = TimesRemaining[i];
				}
			}
			CooldownStart.Broadcast(TimeRemaining);
		}
	}
}


void UWaitCooldownChange::OnAbilityActivatedCallback(UGameplayAbility* GA) const
{
	float TimeRemaining = 0.f;
	const FGameplayTagContainer AssetTags = GA->GetCurrentAbilitySpec()->DynamicAbilityTags;
	if (AssetTags.HasTagExact(this->InputTag))
	{
		if (ASC)
		{
			UGameplayEffect* CDGE = GA->GetCooldownGameplayEffect();
			if (CDGE)
			{
				CDGE->DurationMagnitude.GetStaticMagnitudeIfPossible(GA->GetAbilityLevel(),TimeRemaining);
				CooldownStart.Broadcast(TimeRemaining);
			}
		}
	}
}
