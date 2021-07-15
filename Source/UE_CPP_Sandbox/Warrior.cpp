// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    LastInput = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    float len = LastInput.Size();

    if (len > 1.f)
    {
        LastInput /= len;
    }

    AddMovementInput(GetActorForwardVector(), LastInput.Y);
    AddMovementInput(GetActorRightVector(), LastInput.X);

    LastInput = FVector2D(0.f, 0.f);
}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Forward", this, &AWarrior::Forward);
    PlayerInputComponent->BindAxis("Back", this, &AWarrior::Back);
    PlayerInputComponent->BindAxis("Left", this, &AWarrior::Left);
    PlayerInputComponent->BindAxis("Right", this, &AWarrior::Right);
}

void AWarrior::Forward(float amount)
{
    //AddMovementInput(GetActorForwardVector(), amount);
    LastInput.Y += amount;
}

void AWarrior::Back(float amount)
{
    //AddMovementInput(-GetActorForwardVector(), amount);
    LastInput.Y -= amount;
}

void AWarrior::Right(float amount)
{
    //AddMovementInput(GetActorRightVector(), amount);
    LastInput.X += amount;
}

void AWarrior::Left(float amount)
{
    //AddMovementInput(-GetActorRightVector(), amount);
    LastInput.X -= amount;
}
