#include <iostream>
#include <iomanip>
#include <string>

int main() {
    std::cout << "Welcome to Mission Control!" << std::endl;
    std::cout << "Please enter the astronaut name: ";
    std::string astronautName;
    std::cin >> astronautName;
    std::cout << "Please enter the astronaut age: ";
    int astronautAge;
    if (!(std::cin >> astronautAge)) {
        std::cout << "Invalid input for age\n";
        return 1;
    }

    if (astronautAge < 8 || astronautAge > 18) {
        std::cout << "Age must be between 8 and 18\n";
        return 1;
    }
    std::cout << "Please enter the astronaut height in m: ";
    double astronautHeight;
    if (!(std::cin >> astronautHeight)) {
        std::cout << "Invalid input for height\n";
        return 1;
    }

    if (astronautHeight < 1.0 || astronautHeight > 2.2) {
        std::cout << "Height must be between 1.0 and 2.2 meters\n";
        return 1;
    }
    std::cout << "Please enter the astronaut weight in kg: ";
    float astronautWeight;
    if (!(std::cin >> astronautWeight)) {
        std::cout << "Invalid input for weight\n";
        return 1;
    }

    if (astronautWeight < 20.0 || astronautWeight > 100.0) {
        std::cout << "Weight must be between 20.0 and 100.0 kg\n";
        return 1;
    }
    double astronautBMI = astronautWeight / (astronautHeight * astronautHeight);
    std::cout << "Please enter the astronaut mission distance in km: ";
    double missionDistance;
    if (!(std::cin >> missionDistance)) {
        std::cout << "Invalid input for mission distance\n";
        return 1;
    }

    if (missionDistance <= 0) {
        std::cout << "Mission distance must be bigger than 0\n";
        return 1;
    }
    std::cout << "Please enter the astronaut ship speed in km/s: ";
    float shipSpeed;
    if (!(std::cin >> shipSpeed)) {
        std::cout << "Invalid input for ship speed\n";
        return 1;
    }

    if (shipSpeed <= 0) {
        std::cout << "Ship speed must be a bigger than 0\n";
        return 1;
    }
    std::cout << "Please enter the astronaut has helmet? (1 for yes, 0 for no): ";
    bool hasHelmet;
    while (!(std::cin >> hasHelmet)) {
        std::cout << "Invalid input for helmet status\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return 1;
    }

    std::cout << "=================Mission Control=================" << std::endl;
    std::cout << "Astronaut Name: " << astronautName << std::endl;
    std::cout << "Astronaut Age: " << astronautAge << std::endl;
    std::cout << "Astronaut Height: " << astronautHeight << " m" << std::endl;
    std::cout << "Astronaut Weight: " << astronautWeight << " kg" << std::endl;
    std::cout << "Mission Distance: " << missionDistance << " km" << std::endl;
    std::cout << "Ship Speed: " << shipSpeed << " km/s" << std::endl;
    std::cout << "Astronaut has helmet: " << (hasHelmet ? "Yes" : "No") << std::endl;

    std::cout << "=================Astronaut Report=================" << std::endl;
    std::cout << "Astronaut Name: " << astronautName << std::endl;
    std::cout << "Astronaut Age: " << astronautAge << std::endl;
    std::cout << "Astronaut Height: " << astronautHeight << " m" << std::endl;
    std::cout << "Earth weights the astronaut at " << astronautWeight << " kg" << std::endl;
    std::cout << "Moon weights the astronaut at " << std::fixed << std::setprecision(2) << astronautWeight * 0.165 << " kg\n";
    std::cout << "Mars weights the astronaut at " << std::fixed << std::setprecision(2) << astronautWeight * 0.38 << " kg\n";
    std::cout << "Astronaut BMI: " << std::fixed << std::setprecision(2) << astronautBMI << std::endl;

    std::cout << "==================Mission Time==================" << std::endl;
    std::cout << "Distance default format: " << std::defaultfloat << missionDistance << " km" << std::endl;
    std::cout << "Distance fixed format: " << std::fixed << std::setprecision(2) << missionDistance << " km" << std::endl;
    std::cout << "Distance scientific format: " << std::scientific << std::setprecision(6) << missionDistance << " km" << std::endl;

    double timeSeconds = missionDistance / shipSpeed;
    long long totalSeconds = static_cast<long long>(timeSeconds);
    int days = totalSeconds / 86400;
    int hours = totalSeconds % 86400 / 3600;
    int minutes = totalSeconds % 3600 / 60;
    int seconds = totalSeconds % 60;

    std::cout << "Estimated mission time: ";
    if (days > 0) {
        std::cout << days << " Day" << (days == 1 ? "" : "s") << " ";
    }
    if (hours > 0) {
        std::cout << hours << " Hour" << (hours == 1 ? "" : "s") << " ";
    }
    if (minutes > 0) {
        std::cout << minutes << " Minute" << (minutes == 1 ? "" : "s") << " ";
    }
    if (seconds > 0 || (days == 0 && hours == 0 && minutes == 0)) {
        std::cout << seconds << " Second" << (seconds == 1 ? "" : "s");
    }
    std::cout << std::endl;

    bool isReady =
    astronautAge >= 12 &&
    hasHelmet &&
    shipSpeed > 0 &&
    missionDistance > 0;

    std::cout << "Mission status: "
        << (isReady ? "READY" : "NOT READY")
        << std::endl;

    return 0;
}