// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"


UCLASS()
class PROJECT3003_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float weaponRange{ 1000 };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void fireWeapon(); // not returning anything

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FHitResult InstantShot();
public:
	// called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

// private:
	//void Move_Forward(float AxisValue);;

};