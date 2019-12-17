#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty);

bool PlayGame(int LevelDifficulty) {
    PrintIntroduction(LevelDifficulty);

    int CodeA = rand() % (LevelDifficulty + 1) + LevelDifficulty;
    int CodeB = rand() % (LevelDifficulty + 1) + LevelDifficulty;
    int CodeC = rand() % (LevelDifficulty + 1) + LevelDifficulty;

    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "The sum of the numbers is: " << CodeSum;
    std::cout << "\nThe product of the numbers is:" << CodeProduct;
    std::cout << "\nThe numbers are...?: ";

    int GuessA, GuessB, GuessC;

    // Get user input for 3 fields
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    bool GuessedCorrect = GuessSum == CodeSum && GuessProduct == CodeProduct;

    if (GuessedCorrect) {
        std::cout << "You got it! You're a good person!\n\n";
    } else {
        std::cout << "NOOOO! They gonsta keel yoooo!\n\n";
    }

    return GuessedCorrect;
}

void PrintIntroduction(int LevelDifficulty) {
    std::cout << "\n\nYou're going to be murdered if you can't break into house no. " << LevelDifficulty << "!\n\n";
    std::cout << "You need to enter the correct code to continue...!\n\n";
}

void ClearInputBuffer() {
    std::cin.clear();
    std::cin.ignore();
}

int main() {
    srand(time(NULL));
    bool bLevelComplete = false;
    int LevelDifficulty = 1;
    const int MaxDifficulty = 3;

    do {
        bLevelComplete = PlayGame(LevelDifficulty);
        ClearInputBuffer();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    } while (bLevelComplete && LevelDifficulty <= MaxDifficulty);

    if (bLevelComplete) {
        std::cout << "Woo, you're safe!";
    } else {
        std::cout << "You're dead now. So sad.";
    }

    return 0;
}