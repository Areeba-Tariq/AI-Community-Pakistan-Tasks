#include <iostream>
#include <iomanip>
#include <string>

int main() {
    const double MIN_WEIGHT_SAND_GRAVEL = 49.9;
    const double MAX_WEIGHT_SAND_GRAVEL = 50.1;
    const double MIN_WEIGHT_CEMENT = 24.9;
    const double MAX_WEIGHT_CEMENT = 25.1;

    int numSacksCement, numSacksGravel, numSacksSand;
    int numRejectedSacks = 0;
    double totalWeight = 0.0;

    std::cout << "Enter the number of sacks of cement: ";
    std::cin >> numSacksCement;

    for (int i = 0; i < numSacksCement; ++i) {
        std::string contents;
        double weight;

        std::cout << "Enter contents of the sack (C for cement): ";
        std::cin >> contents;

        std::cout << "Enter weight of the sack in kilograms: ";
        std::cin >> weight;

        if (contents == "C" && weight >= MIN_WEIGHT_CEMENT && weight <= MAX_WEIGHT_CEMENT) {
            totalWeight += weight;
        } else {
            std::cout << "Rejected Sack: ";
            if (contents != "C") {
                std::cout << "Invalid contents. ";
            }
            if (weight < MIN_WEIGHT_CEMENT || weight > MAX_WEIGHT_CEMENT) {
                std::cout << "Invalid weight for cement. ";
            }
            std::cout << std::endl;
            ++numRejectedSacks;
        }
    }

    std::cout << "Enter the number of sacks of gravel: ";
    std::cin >> numSacksGravel;

    for (int i = 0; i < numSacksGravel; ++i) {
        std::string contents;
        double weight;

        std::cout << "Enter contents of the sack (G for gravel): ";
        std::cin >> contents;

        std::cout << "Enter weight of the sack in kilograms: ";
        std::cin >> weight;

        if (contents == "G" && weight >= MIN_WEIGHT_SAND_GRAVEL && weight <= MAX_WEIGHT_SAND_GRAVEL) {
            totalWeight += weight;
        } else {
            std::cout << "Rejected Sack: ";
            if (contents != "G") {
                std::cout << "Invalid contents. ";
            }
            if (weight < MIN_WEIGHT_SAND_GRAVEL || weight > MAX_WEIGHT_SAND_GRAVEL) {
                std::cout << "Invalid weight for gravel. ";
            }
            std::cout << std::endl;
            ++numRejectedSacks;
        }
    }

    std::cout << "Enter the number of sacks of sand: ";
    std::cin >> numSacksSand;

    for (int i = 0; i < numSacksSand; ++i) {
        std::string contents;
        double weight;

        std::cout << "Enter contents of the sack (S for sand): ";
        std::cin >> contents;

        std::cout << "Enter weight of the sack in kilograms: ";
        std::cin >> weight;

        if (contents == "S" && weight >= MIN_WEIGHT_SAND_GRAVEL && weight <= MAX_WEIGHT_SAND_GRAVEL) {
            totalWeight += weight;
        } else {
            std::cout << "Rejected Sack: ";
            if (contents != "S") {
                std::cout << "Invalid contents. ";
            }
            if (weight < MIN_WEIGHT_SAND_GRAVEL || weight > MAX_WEIGHT_SAND_GRAVEL) {
                std::cout << "Invalid weight for sand. ";
            }
            std::cout << std::endl;
            ++numRejectedSacks;
        }
    }

    std::cout << "Total weight of the order: " << std::fixed << std::setprecision(2) << totalWeight << " kilograms" << std::endl;
    std::cout << "Number of sacks rejected from the order: " << numRejectedSacks << std::endl;

    return 0;
}
