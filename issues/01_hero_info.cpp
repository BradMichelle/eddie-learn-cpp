#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::cout << "Enter the hero name: ";
    std::string heroName;
    std::cin >> heroName;

    std::cout << "Enter the hero hp: ";
    int heroHp;
    while (!(std::cin >> heroHp)) {
        std::cout << "Invalid input for HP\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Enter the hero atk: ";
    int heroAtk;
    while (!(std::cin >> heroAtk)) {
        std::cout << "Invalid input for ATK\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Enter the hero speed: ";
    double heroSpeed;
    while (!(std::cin >> heroSpeed)) {
        std::cout << "Invalid input for Speed\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Is the hero has sword? (1 for yes, 0 for no): ";
    bool hasSword;
    while (!(std::cin >> hasSword)) {
        std::cout << "Invalid input for sword status\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "=================Hero Info=================" << std::endl;
    std::cout << "Hero Name: " << heroName << std::endl;
    std::cout << "Hero HP: " << heroHp << std::endl;
    std::cout << "Hero ATK: " << heroAtk << std::endl;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Hero Speed: " << heroSpeed << std::endl;
    std::cout << "Hero has sword: " << (hasSword ? "Yes" : "No") << std::endl;

    return 0;
}
