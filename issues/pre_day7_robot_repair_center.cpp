#include <iostream>
#include <string>
#include <vector>

int readIntInRange(std::string prompt, int minValue, int maxValue) {
    int value;

    std::cout << prompt;
    while(!(value) && value < minValue && value > maxValue) {
        std::cout << "Invalid value. Please enter a value between " << minValue
                                                                    << " and " << maxValue
                                                                    << std::endl;
    }

    return value;
}

double readDoubleInRange(std::string prompt, double minValue, double maxValue) {
    double value;

    std::cout << prompt;
    while(!(value) && value < minValue && value > maxValue) {
        std::cout << "Invalid value. Please enter a value between " << minValue
                                                                    << " and " << maxValue
                                                                    << std::endl;
    }

    return value;
}

bool readYesNo(std::string prompt) {
    bool value;

    std::cout << prompt;
    while(!(value) && value < 0 && value > 1) {
        std::cout << "Invalid value. Please enter a value between 0 and 1. (1 for yes, 0 for no): " << std::endl;
    }
    
    return value;
}

double calculateRepairCost(int damageLevel, double repairCostPerPoint) {
    return damageLevel * repairCostPerPoint;
}

bool needsRepair(int damageLevel) {
    return damageLevel > 0;
}

bool isRobotDangerous(int batteryLevel, int damageLevel) {
    return batteryLevel < 30 || damageLevel > 70;
}

bool isUrgentRepair(int batteryLevel, int damageLevel, bool isCritical) {
    if (isCritical && damageLevel >= 50) {
        return true;
    }

    if (batteryLevel < 20 && damageLevel >= 40) {
        return true;
    }

    return false;
}

int calculatePriorityScore(int batteryLevel, int damageLevel, bool isCritical) {
    int priority = damageLevel;

    if (batteryLevel < 30) {
        priority += 20;
    }

    if (isCritical) {
        priority += 30;
    }

    if (damageLevel >= 80) {
        priority += 20;
    }

    return priority;
}

double calculateTotalRepairCost(std::vector<double> totalRepairCosts) {
    double totalCost = 0;

    for(int i = 0; i < totalRepairCosts.size(); ++i) {
        totalCost += totalRepairCosts[i];
    }

    return totalCost;
}

int countRobotsNeedingRepair(std::vector<int> damageLevels) {
    int count;

    for(int i = 0; i < damageLevels.size(); ++i) {
        if(damageLevels[i] > 0) {
            ++count;
        }
    }

    return count;
}

int countDangerousRobots(
    std::vector<int> batteryLevels,
    std::vector<int> damageLevels
) {
    int count;

    for(int i = 0; i < damageLevels.size(); ++i) {
        if(batteryLevels[i] < 30 && damageLevels[i] > 70) {
            ++count;
        }
    }

    return count;
}

int countUrgentRobots(
    std::vector<int> batteryLevels,
    std::vector<int> damageLevels,
    std::vector<bool> criticalFlags
) {
    int count;

    for(int i = 0; i < criticalFlags.size(); ++i) {
        if((criticalFlags[i] == true && damageLevels[i] >= 50) ||
          (batteryLevels[i] < 20 && damageLevels[i] >= 40)) {
            ++count;
          }
    }

    return count;
}

int findHighestPriorityRobotIndex(std::vector<int> priorityScores) {
    int find = priorityScores[0];

    for(int i = 0; i < priorityScores.size(); ++i) {
        if(priorityScores[i] > find) {
            find = priorityScores[i];
        }
    }

    return find;
}

void printRobotReport(
    std::vector<std::string> robotNames,
    std::vector<int> batteryLevels,
    std::vector<int> damageLevels,
    std::vector<double> repairCostsPerPoint,
    std::vector<bool> criticalFlags,
    std::vector<int> priorityScores,
    std::vector<double> totalRepairCosts
) {
    std::cout << std::endl;
    std::cout << "===== Robot Report =====" << std::endl;

    for (int i = 0; i < robotNames.size(); i++) {
        std::string status;

        if (!needsRepair(damageLevels[i])) {
            status = "OK";
        } else if (isUrgentRepair(batteryLevels[i], damageLevels[i], criticalFlags[i])) {
            status = "URGENT REPAIR";
        } else if (isRobotDangerous(batteryLevels[i], damageLevels[i])) {
            status = "DANGER";
        } else {
            status = "NEEDS REPAIR";
        }

        std::cout << "Robot " << i + 1
                  << " | Name: " << robotNames[i]
                  << " | Battery: " << batteryLevels[i]
                  << " | Damage: " << damageLevels[i]
                  << " | Critical: " << (criticalFlags[i] ? "Yes" : "No")
                  << " | Repair cost: " << totalRepairCosts[i]
                  << " | Priority: " << priorityScores[i]
                  << " | Status: " << status
                  << std::endl;
    }
}

int main() {
    std::cout << "===== Space Robot Repair Center =====" << std::endl;

    std::cout << "Engineer name: ";
    std::string engineerName;
    std::cin >> engineerName;

    int robotCount = readIntInRange("Number of robots (1-10): ", 1, 10);

    std::vector<std::string> robotNames;
    std::vector<int> batteryLevels;
    std::vector<int> damageLevels;
    std::vector<double> repairCostsPerPoint;
    std::vector<bool> criticalFlags;
    std::vector<int> priorityScores;
    std::vector<double> totalRepairCosts;

    for (int robot = 1; robot <= robotCount; robot++) {
        std::cout << std::endl;
        std::cout << "Robot " << robot << std::endl;

        std::cout << "Robot name (no space): ";
        std::string robotName;
        std::cin >> robotName;

        int batteryLevel = readIntInRange("Battery level (0-100): ", 0, 100);
        int damageLevel = readIntInRange("Damage level (0-100): ", 0, 100);
        double repairCostPerPoint = readDoubleInRange(
            "Repair cost per damage point (0-1000): ",
            0.0,
            1000.0
        );
        bool isCritical = readYesNo("Is this robot mission critical? ");

        double totalRepairCost = calculateRepairCost(damageLevel, repairCostPerPoint);
        int priorityScore = calculatePriorityScore(batteryLevel, damageLevel, isCritical);

        robotNames.push_back(robotName);
        batteryLevels.push_back(batteryLevel);
        damageLevels.push_back(damageLevel);
        repairCostsPerPoint.push_back(repairCostPerPoint);
        criticalFlags.push_back(isCritical);
        priorityScores.push_back(priorityScore);
        totalRepairCosts.push_back(totalRepairCost);

        std::cout << "Repair cost: " << totalRepairCost << std::endl;
        std::cout << "Priority score: " << priorityScore << std::endl;

        if (!needsRepair(damageLevel)) {
            std::cout << "Status: OK, no repair needed." << std::endl;
        } else if (isUrgentRepair(batteryLevel, damageLevel, isCritical)) {
            std::cout << "Status: URGENT REPAIR" << std::endl;
        } else if (isRobotDangerous(batteryLevel, damageLevel)) {
            std::cout << "Status: DANGER" << std::endl;
        } else {
            std::cout << "Status: NEEDS REPAIR" << std::endl;
        }
    }

    double totalCost = calculateTotalRepairCost(totalRepairCosts);
    int repairCount = countRobotsNeedingRepair(damageLevels);
    int dangerCount = countDangerousRobots(batteryLevels, damageLevels);
    int urgentCount = countUrgentRobots(batteryLevels, damageLevels, criticalFlags);
    int highestPriorityIndex = findHighestPriorityRobotIndex(priorityScores);

    std::cout << std::endl;
    std::cout << "===== Repair Center Summary =====" << std::endl;
    std::cout << "Engineer: " << engineerName << std::endl;
    std::cout << "Total robots: " << robotCount << std::endl;
    std::cout << "Robots needing repair: " << repairCount << std::endl;
    std::cout << "Dangerous robots: " << dangerCount << std::endl;
    std::cout << "Urgent repair robots: " << urgentCount << std::endl;
    std::cout << "Total repair cost: " << totalCost << std::endl;

    if (highestPriorityIndex >= 0) {
        std::cout << "Highest priority robot: "
                  << robotNames[highestPriorityIndex]
                  << " with priority score "
                  << priorityScores[highestPriorityIndex]
                  << std::endl;
    }

    printRobotReport(
        robotNames,
        batteryLevels,
        damageLevels,
        repairCostsPerPoint,
        criticalFlags,
        priorityScores,
        totalRepairCosts
    );

    return 0;
}