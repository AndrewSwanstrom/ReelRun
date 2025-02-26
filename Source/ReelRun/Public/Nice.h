// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Nice.generated.h"

/**
 * 
 */
UCLASS()
class REELRUN_API UNice : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "What's up, Babygirl")
	static void Hello();
	
};
