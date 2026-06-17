#include <iostream>

int main() {
    int choice;

    while (true) {
        std::cout << "====================" << std::endl;
        std::cout << "1. Start" << std::endl;
        std::cout << "2. Options" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "====================" << std::endl;
        std::cout << "Please select an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Starting the game..." << std::endl;
                break;
            case 2:
                std::cout << "Opening options..." << std::endl;
                break;
            case 3:
                std::cout << "Quitting the game..." << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
    }

    return 0;
}