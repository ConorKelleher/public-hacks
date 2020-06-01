// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The number of possible words is %i"), Words.Num());
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);

    
    for(int Index=0; Index<10; Index++) {
        int WordLen = Words[Index].Len();
        if (WordLen >= 4 && WordLen <= 8) {
            PrintLine(TEXT("%s"), *Words[Index]);
        }
    }
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ProcessGuess(Input);
}

void UBullCowCartridge::SetupGame() {
    HiddenWord = TEXT("both");
    bGameOver = false;
    Lives = HiddenWord.Len();

    PrintLine(TEXT("Welcome to Bulls & Cows!"));

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("Hit <enter> after your guess to submit..."));
}

bool UBullCowCartridge::IsIsogram(FString Word) const {
    bool bIsIsogram = true;
    for (int32 i=0; i<Word.Len()-1; i++) {
        for (int32 j=i+1; j<Word.Len(); j++) {
            if (Word[i] == Word[j]) {
                bIsIsogram = false;
                break;
            }
        }
    }
    return bIsIsogram;
}

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("\nWould you like to play again? (Press Enter)"));
}

void UBullCowCartridge::ProcessGuess(FString Guess) {
    if (bGameOver) {
        // Taking input after game over
        bGameOver = false;
        ClearScreen();
        SetupGame();
        return;
    }

    if (Guess == HiddenWord) {
        // In game and correct
        PrintLine(TEXT("You got it!"));
        EndGame();
        return;
    }

    if (Guess.Len() != HiddenWord.Len()) {
        PrintLine(TEXT("Your guess is the wrong number of characters.\nIt must be %i letters long"), HiddenWord.Len());
        return;
    }

    if (!IsIsogram(Guess)) {
        PrintLine(TEXT("That is not an isogram.\nYour guess must not have any repeating characters"));
        return;
    }
    

    // In game and not correct
    PrintLine(TEXT("NOOP! You are a losing person"));

    if (--Lives > 0) {
        // Still have lives, keep it going
        PrintLine(TEXT("Try again. You have %i lives left"), Lives);
    } else {
        // No more lives, game is over
        ClearScreen();
        PrintLine(TEXT("You're out of lives. Tough luck!"));
        PrintLine(TEXT("The secret word was: %s"), *HiddenWord);
        EndGame();
        return;
    }
}