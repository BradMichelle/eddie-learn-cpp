#include <iostream>
#include <string>

int main() {
    std::cout << "=====Space Training Simulator=====" << std::endl;
    std::cout << "Enter your name (No space): ";
    std::string name;
    std::cin >> name;

    std::cout << "Enter your age (0-120): ";
    int age;
    while (!(std::cin >> age) || age < 0 || age > 120) {
        std::cout << "Invalid age. Enter age from 0 to 120: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Enter the training rounds (1-10): ";
    int trainingRounds;
    while (!(std::cin >> trainingRounds) || trainingRounds < 1 || trainingRounds > 10) {
        std::cout << "Invalid age. Enter training rounds from 1 to 10: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    int passedRounds = 0;
    int failedRounds = 0;
    int totalScore = 0;

    for(int i = 1; i <= trainingRounds; ++i) {
        std::cout << "Round " << i << std::endl;
        std::cout << "Enter oxygen level (0-100): ";
        double oxygenLevel;
        while (!(std::cin >> oxygenLevel) || oxygenLevel < 0 || oxygenLevel > 100) {
            std::cout << "Invalid oxygen level. Enter oxygen level from 0 to 100: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cout << "Enter battery level (0-100): ";
        int batteryLevel;
        while (!(std::cin >> batteryLevel) || batteryLevel < 0 || batteryLevel > 100) {
            std::cout << "Invalid battery level. Enter battery level from 0 to 100: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
 
        if (oxygenLevel >= 80 && batteryLevel >= 50) {
            std::cout << "Round result: PASS" << std::endl;
            ++passedRounds;
            totalScore += 10;
            if (oxygenLevel >= 95.0 && batteryLevel >= 90) {
                std::cout << "Excellent round! Bonus +5." << std::endl;
                totalScore += 5;
            }

        } else {
            std::cout << "Round result: FAIL" << std::endl;
            std::cout << "Reasons:" << std::endl;
            if (oxygenLevel < 80) {
                std::cout << "- Oxygen level is too low" << std::endl;
            }
            if (batteryLevel < 50) {
                std::cout << "- Battery level is too low" << std::endl;
            }
            ++failedRounds;
        }
    }

    std::cout << "=====Training Report=====" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Rounds: " << trainingRounds << std::endl;
    std::cout << "Passed rounds: " << passedRounds << std::endl;
    std::cout << "Failed rounds: " << failedRounds << std::endl;
    std::cout << "Total score: " << totalScore << std::endl;

    return 0;
}