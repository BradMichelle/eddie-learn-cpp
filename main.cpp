#include <iostream>
#include <string>

int main() {
    std::string name;
    std::string birthDay;
    std::string placeOfBirth;

    std::cout << "Enter your name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter your birth day: ";
    std::getline(std::cin >> std::ws, birthDay);

    std::cout << "Enter your place of birth: ";
    std::getline(std::cin >> std::ws, placeOfBirth);

    std::cout << "=================PROFILE CARD==================" << std::endl;
    std::cout << "| Name: " << name << "                            |" << std::endl;
    std::cout << "| Birth Day: " << birthDay << "                        |" << std::endl;
    std::cout << "| Place of Birth: " << placeOfBirth << "                   |" << std::endl;
    std::cout << "===============================================" << std::endl;

    return 0;
}