// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver) {
        // Taking input after game over
        bGameOver = false;
        ClearScreen();
        SetupGame();
    } else if (Input == HiddenWord) {
        // In game and correct
        PrintLine(TEXT("You got it!"));
        EndGame();
    } else {
        // In game and not correct
        if (!IsIsogram(Input)) {
            PrintLine(TEXT("That is not an isogram.\nYour guess must not have any repeating characters"));
        } else if (Input.Len() != HiddenWord.Len()) {
            PrintLine(TEXT("Your guess is the wrong number of characters.\nIt must be %i letters long"), HiddenWord.Len());
        } else {
            PrintLine(TEXT("NOOP! You are a losing person"));
            --Lives;
        }

        if (Lives > 0) {
            // Still have lives, keep it going
            PrintLine(TEXT("Try again. You have %i lives left"), Lives);
        } else {
            // No more lives, game is over
            PrintLine(TEXT("You're out of lives. Tough luck!"));
            EndGame();
        }
    }
}

void UBullCowCartridge::SetupGame() {
    HiddenWord = TEXT("both");
    bGameOver = false;
    Lives = HiddenWord.Len();

    PrintLine(TEXT("Welcome to Bulls & Cows!"));

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("Hit <enter> after your guess to submit..."));
}

bool UBullCowCartridge::IsIsogram(FString str) {
    return true;
}

void UBullCowCartridge::EndGame() {
    PrintLine(TEXT("\nWould you like to play again? (Press Enter)"));
    bGameOver = true;
}
