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
    while (!(std::cin >> oxygenLevel) || oxygenLevel < 0.0 || oxygenLevel > 100.0) {
        std::cout << "Invalid input for oxygen level. Please enter a value between 0 and 100.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Battery level: " << std::endl;
    int batteryLevel;
    while (!(std::cin >> batteryLevel) || batteryLevel < 0 || batteryLevel > 100) {
        std::cout << "Invalid input for battery level. Please enter a value between 0 and 100.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    bool canEnter =
        age >= 12 &&
        hasHelmet &&
        oxygenLevel >= 80.0 &&
        batteryLevel >= 50;

    if (canEnter) {
        std::cout << "Access granted!" << std::endl;
    } else {
        std::cout << "Access denied." << std::endl;
        std::cout << "Reasons:" << std::endl;

        if (age < 12) {
            std::cout << "- Too young" << std::endl;
        }

        if (!hasHelmet) {
            std::cout << "- Helmet required" << std::endl;
        }

        if (oxygenLevel < 80.0) {
            std::cout << "- Oxygen too low" << std::endl;
        }

        if (batteryLevel < 50) {
            std::cout << "- Battery too low" << std::endl;
        }
    }

    return 0;
}