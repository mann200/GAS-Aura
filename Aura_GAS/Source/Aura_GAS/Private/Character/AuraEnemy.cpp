 // Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AI/AuraAIController.h"
#include "Aura_GAS/Aura_GAS.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

 AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

 	bUseControllerRotationPitch = false;
 	bUseControllerRotationRoll = false;
 	bUseControllerRotationYaw = false;
 	GetCharacterMovement()->bUseControllerDesiredRotation = true;

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");

	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(GetRootComponent());

 	BaseWalkSpeed = 250.f;
}

 void AAuraEnemy::PossessedBy(AController* NewController)
 {
	 Super::PossessedBy(NewController);

 	if(!HasAuthority()) return;
 	AuraAIController = Cast<AAuraAIController>(NewController);
 	AuraAIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
 	AuraAIController->RunBehaviorTree(BehaviorTree);
 	AuraAIController->GetBlackboardComponent()->SetValueAsBool(FName("HitReacting"),false);
 	AuraAIController->GetBlackboardComponent()->SetValueAsBool(FName("RangedAttacker"),CharacterClass != ECharacterClass::Warrior);

 	
 }

 void AAuraEnemy::HighLightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);

	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemy::UnHighLightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
	//GetMesh()->SetCustomDepthStencilValue(250);
}

 void AAuraEnemy::SetCombatTarget_Implementation(AActor* InCombatTarget)
 {
	 CombatTarget = InCombatTarget;
 }

 AActor* AAuraEnemy::GetCombatTarget_Implementation() const
 {
	 return CombatTarget;
 }

 int32 AAuraEnemy::GetPlayerLevel_Implementation()
{
	return Level;
}

 void AAuraEnemy::Die(const FVector& DeathImpulse)
 {
 	SetLifeSpan(LifeSpan);
 	if (AuraAIController)
 	{
 		AuraAIController->GetBlackboardComponent()->SetValueAsBool(FName("Dead"),true);
 	}
 	Super::Die(DeathImpulse);
 }

 void AAuraEnemy::HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
 {
 	//UE_LOG(LogTemp,Error,TEXT("%s"),*CallbackTag.ToString());

 	bHitReacting = NewCount > 0;
 	GetCharacterMovement()->MaxWalkSpeed = bHitReacting ? 0.f : BaseWalkSpeed;
    if (AuraAIController && AuraAIController->GetBlackboardComponent())
    {
    	AuraAIController->GetBlackboardComponent()->SetValueAsBool(FName("HitReacting"),bHitReacting);
    }
 }

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();
 	GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
	InitAbilityActorInfo();
	if (HasAuthority())
	{
		UAuraAbilitySystemLibrary::GiveStartupAbility(this,AbilitySystemComponent,CharacterClass);
	}
 	

	if(UAuraUserWidget* AuraUserWidget = Cast<UAuraUserWidget>(HealthBar->GetUserWidgetObject()))
	{
		AuraUserWidget->SetWidgetController(this);
	}
 	
	if (const UAuraAttributeSet* AuraSet = CastChecked<UAuraAttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChange.Broadcast(Data.NewValue);
			});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChange.Broadcast(Data.NewValue);
			});
		
		AbilitySystemComponent->RegisterGameplayTagEvent(FAuraGameplayTags::Get().Effects_HitReact,EGameplayTagEventType::NewOrRemoved).AddUObject(this,&AAuraEnemy::HitReactTagChanged);
		
		OnHealthChange.Broadcast(AuraSet->GetHealth());
		OnMaxHealthChange.Broadcast(AuraSet->GetMaxHealth());
	}
	
}

void AAuraEnemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
 	AbilitySystemComponent->RegisterGameplayTagEvent(FAuraGameplayTags::Get().Debuff_Stun,EGameplayTagEventType::NewOrRemoved).AddUObject(this,&AAuraEnemy::StunTagChanged);
 	
	if (HasAuthority())
	{
		InitializeDefaultAttribute();
	}
 	OnAscRegistered.Broadcast(AbilitySystemComponent);
}

void AAuraEnemy::InitializeDefaultAttribute() const
{
	UAuraAbilitySystemLibrary::InitializeDefaultAttrabutes(this,CharacterClass,Level,AbilitySystemComponent);
}

 void AAuraEnemy::StunTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
 {
	 Super::StunTagChanged(CallbackTag, NewCount);

 	if (AuraAIController && AuraAIController->GetBlackboardComponent())
 	{
 		AuraAIController->GetBlackboardComponent()->SetValueAsBool(FName("Stunned"),bIsStunned);
 	}
 }
