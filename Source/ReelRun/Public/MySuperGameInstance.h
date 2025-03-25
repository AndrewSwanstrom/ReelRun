// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MySuperGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class REELRUN_API UMySuperGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;

	UFUNCTION()
	virtual void BeginLoadingScreen(const FString& MapName);
	UFUNCTION()
	virtual void EndLoadingScreen(UWorld* InLoadedWorld);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading Screen")
	TSubclassOf<class UUserWidget> LoadingScreenWidget;
};
