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

    std::cout << "==================Mission Status==================" << std::endl;
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

    std::cout << "Mission status: ";
    if (isReady) {
        std::cout << "READY";
    } else {
        std::cout << "NOT READY BECAUSE ";
        if (astronautAge < 12 && !hasHelmet && shipSpeed <= 0 && missionDistance <= 0) {
            std::cout << "the astronaut is too young, doesn't have a helmet, the ship speed is not positive, and the mission distance is not positive.";
        } else if (astronautAge < 12 && !hasHelmet && shipSpeed <= 0) {
            std::cout << "the astronaut is too young, doesn't have a helmet, and the ship speed is not positive.";
        } else if (astronautAge < 12 && !hasHelmet && missionDistance <= 0) {
            std::cout << "the astronaut is too young, doesn't have a helmet, and the mission distance is not positive.";
        } else if (astronautAge < 12 && shipSpeed <= 0 && missionDistance <= 0) {
            std::cout << "the astronaut is too young, the ship speed is not positive, and the mission distance is not positive.";
        } else if (!hasHelmet && shipSpeed <= 0 && missionDistance <= 0) {
            std::cout << "the astronaut doesn't have a helmet, the ship speed is not positive, and the mission distance is not positive.";
        } else if (astronautAge < 12 && !hasHelmet) {
            std::cout << "the astronaut is too young and doesn't have a helmet.";
        } else if (astronautAge < 12 && shipSpeed <= 0) {
            std::cout << "the astronaut is too young and the ship speed is not positive.";
        } else if (astronautAge < 12 && missionDistance <= 0) {
            std::cout << "the astronaut is too young and the mission distance is not positive.";
        } else if (!hasHelmet && shipSpeed <= 0) {
            std::cout << "the astronaut doesn't have a helmet and the ship speed is not positive.";
        } else if (!hasHelmet && missionDistance <= 0) {
            std::cout << "the astronaut doesn't have a helmet and the mission distance is not positive.";
        } else if (shipSpeed <= 0 && missionDistance <= 0) {
            std::cout << "the ship speed is not positive and the mission distance is not positive.";
        } else if (astronautAge < 12) {
            std::cout << "the astronaut is too young.";
        } else if (!hasHelmet) {
            std::cout << "the astronaut doesn't have a helmet.";
        } else if (shipSpeed <= 0) {
            std::cout << "the ship speed is not positive.";
        } else if (missionDistance <= 0) {
            std::cout << "the mission distance is not positive.";
        }
    }

    std::cout << "Comment about BMI: " << std::endl;
    if (astronautBMI < 15.0) {
        std::cout << "Too light, the astronaut may need to gain some weight for the mission." << std::endl;
    } else if (15 <= astronautBMI && astronautBMI < 18.5) {
        std::cout << "Underweight, the astronaut may need to gain some weight for the mission." << std::endl;
    } else if (18.5 <= astronautBMI && astronautBMI < 25.0) {
        std::cout << "Normal weight, the astronaut is in good shape for the mission." << std::endl;
    } else if (25.0 <= astronautBMI && astronautBMI < 30.0) {
        std::cout << "Overweight, the astronaut may need to lose some weight for the mission." << std::endl;
    } else {
        std::cout << "Obese, the astronaut may need to lose a significant amount of weight for the mission." << std::endl;
    }

    std::cout << "Comment about time Hours: " << std::endl;
    if (hours < 1) {
        std::cout << "The mission is very short, the astronaut may need to prepare for a longer mission." << std::endl;
    } else if (1 <= hours && hours < 24) {
        std::cout << "The mission is of moderate length, the astronaut should be prepared for the mission." << std::endl;
    } else {
        std::cout << "The mission is long, the astronaut should be well-prepared for the mission." << std::endl;
    }

    return 0;
}