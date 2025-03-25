// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance_P.h"
#include "MoviePlayer.h"
#include "Blueprint/UserWidget.h"

void UGameInstance_P::Init()
{
    Super::Init();

    FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UGameInstance_P::BeginLoadingScreen);
    FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UGameInstance_P::EndLoadingScreen);
}

void UGameInstance_P::BeginLoadingScreen(const FString& MapName)
{
#if WITH_EDITOR
    // If GEngine is available, display a debug message
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Loading Start"));
    }
#endif

    if (!IsRunningDedicatedServer())
    {
        FLoadingScreenAttributes LoadingScreen;
        LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
        LoadingScreen.MinimumLoadingScreenDisplayTime = 2.0f;
        UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), LoadingScreenWidget);
        LoadingScreen.WidgetLoadingScreen = Widget -> TakeWidget();

        GetMoviePlayer() -> SetupLoadingScreen(LoadingScreen);
    }
}

void UGameInstance_P::EndLoadingScreen(UWorld* InLoadedWorld)
{
#if WITH_EDITOR
    // Debug message to show that the loading screen has ended.
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, TEXT("Loading End"));
    }
#endif
}
