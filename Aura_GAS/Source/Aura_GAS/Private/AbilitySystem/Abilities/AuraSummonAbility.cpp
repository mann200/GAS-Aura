// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/AuraSummonAbility.h"

TArray<FVector> UAuraSummonAbility::GetSpawnLocation()
{
	const FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector Location = GetAvatarActorFromActorInfo()->GetActorLocation();
	const float DeltaSpread = SpawnSpread / NumMinions;

	//const FVector RightOfSpread = Forward.RotateAngleAxis(SpawnSpread / 2.f,FVector::UpVector);
	const FVector LeftOfSpread = Forward.RotateAngleAxis(-SpawnSpread / 2.f,FVector::UpVector);

	TArray<FVector> SpawnLocation;
	for (int32 i = 0;i < NumMinions;i++)
	{
		const FVector Direction = LeftOfSpread.RotateAngleAxis(DeltaSpread * i,FVector::UpVector);
		FVector ChosenSpawnLocation = Location + Direction * FMath::FRandRange(MinSpawnDistance,MaxSpawnDistance);

		FHitResult HitResult;
		GetWorld()->LineTraceSingleByChannel(HitResult,ChosenSpawnLocation,ChosenSpawnLocation - FVector(0,0,400.f),ECC_Visibility);
		if (HitResult.bBlockingHit)
		{
			ChosenSpawnLocation = HitResult.ImpactPoint;
		}
		SpawnLocation.Add(ChosenSpawnLocation);
	}
	
	return SpawnLocation;
}

TSubclassOf<APawn> UAuraSummonAbility::GetRandomMinionClass()
{
	int32 Seletion = FMath::RandRange(0,MinionClasses.Num() - 1);
	return MinionClasses[Seletion];
}
