#include <iostream>

int main() {
    while (true) {
        std::cout << "This is an infinite loop. Press Ctrl+C to exit." << std::endl;
        int choice;
        std::cout << "Enter 1 to continue or 0 to exit: ";
        while (!(std::cin >> choice) || (choice != 0 && choice != 1)) {
            std::cout << "Invalid input. Please enter 1 to continue or 0 to exit: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(10000, '\n'); // Discard invalid input
        }
        if (choice == 0) {
            break;
        }
    }
    
    for(int i = 0; i <= 5; ++i) {
        if(i == 3) {
            std::cout << "i is equal to 3" << std::endl;
            break; // Exit the loop when i is 3
        }
        std::cout << "Current value of i: " << i << std::endl;
        std::cout << "Enter your height in cm (50-250): ";
        int height;
        while (!(std::cin >> height) || height < 50 || height > 250) {
            std::cout << "Invalid input. Please enter a valid height in cm (50-250): ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(10000, '\n'); // Discard invalid input
        }
    }

    int a = 1;
    int b = ++a;
    int c = a++;
    std::cout << "Value of a: " << a << std::endl; // a is now 2
    std::cout << "Value of b: " << b << std::endl; // b is 2 (pre-increment)
    std::cout << "Value of c: " << c << std::endl; // c is 2 (post-increment, but a was incremented after assignment
    return 0;


    //for (initialize; condition; increment) {
        // code to be executed
    //}
}