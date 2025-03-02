// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags() 
{
	//使用 Gameplay Tags 管理器（UGameplayTagsManager）在运行时添加一个本地的 Gameplay Tag。

	/*
	 * Primary Attributes
	 */
	GameplayTags.Attribute_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Primary.Strength"),
		FString("Increases physical damage"));

	GameplayTags.Attribute_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Attributes.Primary.Intelligence"),
	FString("Increases magical damage"));

	GameplayTags.Attribute_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Attributes.Primary.Resilience"),
	FString("Increases Armor and Armor Penetration"));

	GameplayTags.Attribute_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Attributes.Primary.Vigor"),
	FString("Increases Health"));

	/*
	 * Secondary Attributes
	 */
	GameplayTags.Attribute_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.Armor"),
		FString("Reduces damage taken,improves Block Chance"));

	GameplayTags.Attribute_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.ArmorPenetration"),
		FString("Ignores Percentage of enemy Armor,increases Critical Hit Change"));

	GameplayTags.Attribute_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.BlockChance"),
		FString("Chance to cut incoming damage in half"));

	GameplayTags.Attribute_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.CriticalHitChance"),
		FString("Chance to double damage plus critical hit bonus"));

	GameplayTags.Attribute_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.CriticalHitDamage"),
		FString("Bouns damage added when a critical hit is scared"));

	GameplayTags.Attribute_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.CriticalHitResistance"),
		FString("Reduces Critical Hit Chance of attacking enemies"));

	GameplayTags.Attribute_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.HealthRegeneration"),
		FString("Amount of Health regenerated every 1 second"));

	GameplayTags.Attribute_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.ManaRegeneration"),
		FString("Amount of Mana regenerated every 1 second"));

	GameplayTags.Attribute_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.MaxHealth"),
		FString("Maximum amount of Health obtainable"));

	GameplayTags.Attribute_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Attributes.Secondary.MaxMana"),
		FString("Maximum amount of Mana obtainable"));

	/*
	 * Input Tags
	 */ 
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.LMB"),
		FString("Input Tag for Left Mouse Button"));
	
	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.RMB"),
		FString("Input Tag for Right Mouse Button"));
	
	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.1"),
		FString("Input Tag for 1 key"));

	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.2"),
	FString("Input Tag for 2 key"));

	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.3"),
	FString("Input Tag for 3 key"));

	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag
		(FName("InputTag.4"),
	FString("Input Tag for 4 key"));

	GameplayTags.InputTag_Passive_1 = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("InputTag.Passive.1"),
FString("Input Tag Passive Ability 1"));

	GameplayTags.InputTag_Passive_2 = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("InputTag.Passive.2"),
FString("Input Tag Passive Ability 2"));
	/*
	 * Resistance 
	 */
	GameplayTags.Attribute_Resistance_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Attributes.Resistance.Arcane"),
FString("Resistance to Arcane damage"));

	GameplayTags.Attribute_Resistance_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Attributes.Resistance.Lightning"),
FString("Resistance to Lightning damage"));

	GameplayTags.Attribute_Resistance_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Attributes.Resistance.Fire"),
FString("Resistance to Fire damage"));

	GameplayTags.Attribute_Resistance_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Attributes.Resistance.Physical"),
FString("Resistance to Physical damage"));

	/*
	 * Debuff
	 */
	GameplayTags.Debuff_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Debuff.Arcane"),
FString("Debuff for Arcane damage"));

	GameplayTags.Debuff_Burn = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Debuff.Burn"),
FString("Debuff for Fire damage"));

	GameplayTags.Debuff_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Debuff.Physical"),
FString("Debuff for Physical damage"));

	GameplayTags.Debuff_Stun = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Debuff.Stun"),
FString("Debuff for Lightning damage"));

	GameplayTags.Debuff_Chance = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Debuff.Chance"),
FString("Debuff Chance"));

	GameplayTags.Debuff_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Debuff.Damage"),
FString("Debuff Damage"));

	GameplayTags.Debuff_Duration = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Debuff.Duration"),
FString("Debuff Duration"));

	GameplayTags.Debuff_Frequency = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Debuff.Frequency"),
FString("Debuff Frequency"));
	
	/*
	 * Meta Attribute
	 */
	GameplayTags.Attribute_Meta_IncomingXP = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Attributes.Meta.IncomingXP"),
FString("Incoming XP Meta Attribute"));

	/*
	 * Damage Tags
	 */
	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Damage"),
FString("Damage"));
	
	GameplayTags.Damage_Fire = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Damage.Fire"),
FString("Fire Damage Type"));

	GameplayTags.Damage_Lightning = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Damage.Lightning"),
FString("Lightning Damage Type"));

	GameplayTags.Damage_Arcane = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Damage.Arcane"),
FString("Arcane Damage Type"));

	GameplayTags.Damage_Physical = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Damage.Physical"),
FString("Physical Damage Type"));

	/*
	 * Map of Damage Types to Resistances
	 */
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Arcane,GameplayTags.Attribute_Resistance_Arcane);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Lightning,GameplayTags.Attribute_Resistance_Lightning);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Fire,GameplayTags.Attribute_Resistance_Fire);
	GameplayTags.DamageTypesToResistance.Add(GameplayTags.Damage_Physical,GameplayTags.Attribute_Resistance_Physical);

	/*
	 * Map of Damage Types to Debuff
	 */
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Arcane,GameplayTags.Debuff_Arcane);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Fire,GameplayTags.Debuff_Burn);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Lightning,GameplayTags.Debuff_Stun);
	GameplayTags.DamageTypesToDebuffs.Add(GameplayTags.Damage_Physical,GameplayTags.Debuff_Physical);
	
	/*
	 * HitReact
	 */
	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag
	(FName("Effects.HitReact"),
FString("Tag granted when Hit Reacting"));

	/*
	 * Abilities
	 */
	GameplayTags.Abilities_None = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.None"),
FString("No Ability - like the nullptr for Ability Tags"));

	
	GameplayTags.Abilities_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Attack"),
FString("Attack Ability Tag"));

	GameplayTags.Abilities_Summon = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Summon"),
FString("Summon Ability Tag"));

	GameplayTags.Abilities_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.HitReact"),
FString("HitReact Ability Tag"));

	GameplayTags.Abilities_Status_Eligible = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Status.Eligible"),
FString("Eligible Status"));

	GameplayTags.Abilities_Status_Equipped = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Status.Equipped"),
FString("Equipped Status"));

	GameplayTags.Abilities_Status_Locked = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Status.Locked"),
FString("Locked Status"));

	GameplayTags.Abilities_Status_Unlocked = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Status.Unlocked"),
FString("Unlocked Status"));

	GameplayTags.Abilities_Type_None = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Type.None"),
FString("Type None"));

	GameplayTags.Abilities_Type_Offensive = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Type.Offensive"),
FString("Type Offensive"));

	GameplayTags.Abilities_Type_Passive = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Type.Passive"),
FString("Type Passive"));

	/*
	 * offensive Spells
	 */

	GameplayTags.Abilities_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Fire.FireBolt"),
FString("FireBolt Ability Tag"));

	GameplayTags.Abilities_Fire_FireBlast = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Fire.FireBlast"),
FString("FireBlast Ability Tag"));

	GameplayTags.Abilities_Lightning_Electrocute = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Lightning.Electrocute"),
FString("Electrocute Ability Tag"));

	GameplayTags.Abilities_Arcane_ArcaneShards = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Arcane.ArcaneShards"),
FString("ArcaneShards Ability Tag"));

	/*
	 * Passive Spells
	 */
	GameplayTags.Abilities_Passive_LiftSiphon = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Passive.LiftSiphon"),
FString("Lift Siphon"));

	GameplayTags.Abilities_Passive_LiftSiphon = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Passive.ManaSiphon"),
FString("Mana Siphon"));

	GameplayTags.Abilities_Passive_LiftSiphon = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Abilities.Passive.HaloOfProtection"),
FString("Halo Of Protection"));

	/*
	 * Cooldown
	 */
	GameplayTags.Cooldown_Fire_FireBolt = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Cooldown.Fire.FireBolt"),
FString("FireBolt Cooldown Tag"));

	/*
	 * CombatSocket
	 */
	GameplayTags.CombatSocket_Weapon = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("CombatSocket.Weapon"),
FString("Weapon"));

	GameplayTags.CombatSocket_LeftHand = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("CombatSocket.LeftHand"),
FString("Left Hand"));

	GameplayTags.CombatSocket_RightHand = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("CombatSocket.RightHand"),
FString("Right Hand"));

	GameplayTags.CombatSocket_Tail= UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("CombatSocket.Tail"),
FString("Tail"));

	/*
	 * MontageTag
	 */
	GameplayTags.Montage_Attack_1 = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Montage.Attack.1"),
FString("Attack 1"));
	
	GameplayTags.Montage_Attack_2 = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Montage.Attack.2"),
FString("Attack 2"));
	
	GameplayTags.Montage_Attack_3 = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Montage.Attack.3"),
FString("Attack 3"));
	
	GameplayTags.Montage_Attack_4 = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Montage.Attack.4"),
FString("Attack 4"));

	/*
	 * Player Tags
	 */
	GameplayTags.Player_Block_CursorTrace = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Player.Block.CursorTrace"),
FString("Block tracing under the cursor"));

	GameplayTags.Player_Block_InputHeld = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Player.Block.InputHeld"),
FString("Block Input Held callback for input"));

	GameplayTags.Player_Block_InputPressed = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Player.Block.InputPressed"),
FString("Block Input Pressed callback for input"));

	GameplayTags.Player_Block_InputReleased = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("Player.Block.InputReleased"),
FString("Block Input Released callback for input"));

	/*
	 * GameplayCue
	 */
	GameplayTags.GameplayCue_FireBlast = UGameplayTagsManager::Get().AddNativeGameplayTag
(FName("GameplayCue.FireBlast"),
FString("FireBlast GameplayCue Tag"));
	
}
