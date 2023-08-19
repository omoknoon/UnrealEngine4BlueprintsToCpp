// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Grabber.h"

#include "FirstPersonCharacter.generated.h"

UCLASS()
class BLUEPRINTSTOCPP_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFirstPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	void Forward(float AxisValue);
	void Right(float AxisValue);
	void LookUp(float AxisValue);
	void LookRight(float AxisValue);

	void Jump();
	void Grab();
	void Release();

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	UGrabber* GetGrabber() const;
};
