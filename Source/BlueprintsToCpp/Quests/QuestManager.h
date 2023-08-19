// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestInfo.h"
#include "QuestManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCompletedQuestSignature, int32, Index);

UCLASS()
class BLUEPRINTSTOCPP_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestInfo> QuestList;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CompleteQuest(FName QuestId, bool CompleteWholeQuest);

protected:
	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	int32 GetQuestIndex(FName QuestId) const;

public:
	UFUNCTION(BlueprintPure)
	FQuestInfo GetQuest(FName Name) const;

	UFUNCTION(BlueprintPure, BlueprintImplementableEvent)
	bool IsActiveQuest(FName QuestId) const;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FCompletedQuestSignature CompletedQuest;
};
