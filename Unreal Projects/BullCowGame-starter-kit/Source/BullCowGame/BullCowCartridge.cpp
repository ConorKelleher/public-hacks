// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    PrintLine(TEXT("Welcome to Bulls & Cows!"));

    HiddenWord = TEXT("bother");
    Lives = 5;

    PrintLine(TEXT("Guess the 4 letter word"));
    PrintLine(TEXT("Hit <enter> after your guess to submit..."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    if (Input == HiddenWord) {
        PrintLine(TEXT("You got it!"));
    } else {
        PrintLine(TEXT("NOOP! You are a losing person"));

        if (--Lives > 0) {
            PrintLine(TEXT("Try again. You have some lives left"));
        } else {
            PrintLine(TEXT("You're out of lives. Tough luck!"));
        }
    }
}