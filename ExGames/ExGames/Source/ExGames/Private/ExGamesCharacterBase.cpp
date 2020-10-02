// Fill out your copyright notice in the Description page of Project Settings.


#include "ExGamesCharacterBase.h"

// Sets default values
AExGamesCharacterBase::AExGamesCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExGamesCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExGamesCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AExGamesCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

