#include <iostream>

int main() {
    int secretNumber = 7;
    int guess;
    int maxAttempts = 5;
    bool isWin = false;

    std::cout << "===== Number Guess Trainer =====" << std::endl;

    for (int attempt = 1; attempt <= maxAttempts; attempt++) {
        std::cout << "Attempt " << attempt << "/" << maxAttempts << std::endl;
        std::cout << "Guess a number from 1 to 10: ";

        while (!(std::cin >> guess) || guess < 1 || guess > 10) {
            std::cout << "Invalid guess. Enter a number from 1 to 10: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        if (guess == secretNumber) {
            std::cout << "Correct! You win!" << std::endl;
            isWin = true;
            break;
        } else if (guess < secretNumber) {
            std::cout << "Too low." << std::endl;
        } else {
            std::cout << "Too high." << std::endl;
        }

        std::cout << std::endl;
    }

    if (!isWin) {
        std::cout << "You lose. The secret number was "
                  << secretNumber << "." << std::endl;
    }

    return 0;
}