#include <iostream>

int main() {
    std::cout << "Welcome to the Mini Programme!" << std::endl;
    std::cout << "Please enter your age: ";
    int age;
    if (!(std::cin >> age)) {
        std::cout << "Invalid input for age\n";
        return 1;
    }

    std::cout << "Do you have a helmet? (1 for yes, 0 for no): ";
    bool hasHelmet;
    if (!(std::cin >> hasHelmet)) {
        std::cout << "Invalid input for helmet status\n";
        return 1;
    }

    std::cout << "Oxygen level: ";
    double oxygenLevel;
    if (!(std::cin >> oxygenLevel)) {
        std::cout << "Invalid input for oxygen level\n";
        return 1;
    }

    bool canEnter = age >= 12 && hasHelmet && oxygenLevel > 80.0;
    if (canEnter) {
        std::cout << "Access granted!" << std::endl;
    } else {
        std::cout << "Access denied. " << std::endl;
        if (age < 12 && !hasHelmet && oxygenLevel <= 80.0) {
            std::cout << "You are too young, don't have a helmet, and your oxygen level is too low." << std::endl;
        } else if (age < 12 && !hasHelmet) {
            std::cout << "You are too young and don't have a helmet." << std::endl;
        } else if (age < 12 && oxygenLevel <= 80.0) {
            std::cout << "You are too young and your oxygen level is too low." << std::endl;
        } else if (!hasHelmet && oxygenLevel <= 80.0) {
            std::cout << "You don't have a helmet and your oxygen level is too low." << std::endl;
        } else if (age < 12) {
            std::cout << "You are too young." << std::endl;
        } else if (!hasHelmet) {
            std::cout << "You don't have a helmet." << std::endl;
        } else if (oxygenLevel <= 80.0) {
            std::cout << "Your oxygen level is too low." << std::endl;
        }
    }

    return 0;
}