#include <iostream>
#include <cmath>

int main() {
    int a;
    int b;
    a++;
    std::cout << "Hello C++ learning environment!\n";
    std::cout << "Enter a value for a: ";
    std::cin >> a;
    std::cout << "The value of a is: " << a << std::endl;
    std::cout << "Enter a value for b: ";
    std::cin >> b;
    std::cout << "The value of b is: " << b << std::endl;

    int power = std::pow(a, b);
    std::cout << a << " raised to the power of " << b << " is: " << power << std::endl;

    
    
    return 0;
}
