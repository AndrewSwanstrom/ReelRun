// Fill out your copyright notice in the Description page of Project Settings.


#include "MySuperGameInstance.h"
#include "MoviePlayer.h"
#include "Blueprint/UserWidget.h"

void UMySuperGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UMySuperGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UMySuperGameInstance::EndLoadingScreen);
}

void UMySuperGameInstance::BeginLoadingScreen(const FString& MapName)
{
	if (GetMoviePlayer() -> IsMovieCurrentlyPlaying())
	{
		return;
	}

	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		LoadingScreen.MinimumLoadingScreenDisplayTime = 5.0f;
		UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenWidget);
		LoadingScreen.WidgetLoadingScreen = Widget -> TakeWidget();

		GetMoviePlayer() -> SetupLoadingScreen(LoadingScreen);
	}
}

void UMySuperGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
	
}

