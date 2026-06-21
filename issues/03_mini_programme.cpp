#include <iostream>

int main() {
    std::cout << "Welcome to the Mini Programme!" << std::endl;
    std::cout << "Please enter your age: " << std::endl;
    int age;
    while (!(std::cin >> age)) {
        std::cout << "Invalid input for age\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Do you have a helmet? (1 for yes, 0 for no): " << std::endl;
    bool hasHelmet;
    while (!(std::cin >> hasHelmet)) {
        std::cout << "Invalid input for helmet status\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Do you have a helmet? (1 for yes, 0 for no): " << std::endl;
    }

    std::cout << "Oxygen level: " << std::endl;
    double oxygenLevel;
    while (!(std::cin >> oxygenLevel)) {
        std::cout << "Invalid input for oxygen level\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Oxygen level: " << std::endl;
    }

    std::cout << "Battery level: " << std::endl;
    int batteryLevel;
    while (!(std::cin >> batteryLevel)) {
        std::cout << "Invalid input for battery level\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    bool canEnter = age >= 12 && hasHelmet && oxygenLevel > 80.0 && batteryLevel > 20;
    if (canEnter) {
        std::cout << "Access granted!" << std::endl;
    } else {
        std::cout << "Access denied." << std::endl;
        if (age < 12 && !hasHelmet && oxygenLevel <= 80.0 && batteryLevel <= 20) {
            std::cout << "You are too young, don't have a helmet, your oxygen level is too low, and your battery level is too low." << std::endl;
        } else if (age < 12 && !hasHelmet && batteryLevel <= 20) {
            std::cout << "You are too young, don't have a helmet, and your battery level is too low." << std::endl;
        } else if (age < 12 && oxygenLevel <= 80.0 && batteryLevel <= 20) {
            std::cout << "You are too young, your oxygen level is too low, and your battery level is too low." << std::endl;
        } else if (!hasHelmet && oxygenLevel <= 80.0 && batteryLevel <= 20) {
            std::cout << "You don't have a helmet, your oxygen level is too low, and your battery level is too low." << std::endl;
        } else if (age < 12 && !hasHelmet) {
            std::cout << "You are too young and don't have a helmet." << std::endl;
        } else if (age < 12 && oxygenLevel <= 80.0) {
            std::cout << "You are too young and your oxygen level is too low." << std::endl;
        } else if (!hasHelmet && oxygenLevel <= 80.0) {
            std::cout << "You don't have a helmet and your oxygen level is too low." << std::endl;
        } else if (age < 12 && batteryLevel <= 20) {
            std::cout << "You are too young and your battery level is too low." << std::endl;
        } else if (!hasHelmet && batteryLevel <= 20) {
            std::cout << "You don't have a helmet and your battery level is too low." << std::endl;
        } else if (oxygenLevel <= 80.0 && batteryLevel <= 20) {
            std::cout << "Your oxygen level is too low and your battery level is too low." << std::endl;
        } else if (age < 12) {
            std::cout << "You are too young." << std::endl;
        } else if (!hasHelmet) {
            std::cout << "You don't have a helmet." << std::endl;
        } else if (oxygenLevel <= 80.0) {
            std::cout << "Your oxygen level is too low." << std::endl;
        } else if (batteryLevel <= 20) {
            std::cout << "Your battery level is too low." << std::endl;
        }
    }

    return 0;
}