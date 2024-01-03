#include <iostream>
#include <iomanip>
#include <string>

int main() {
    const double MIN_WEIGHT_SAND_GRAVEL = 49.9;
    const double MAX_WEIGHT_SAND_GRAVEL = 50.1;
    const double MIN_WEIGHT_CEMENT = 24.9;
    const double MAX_WEIGHT_CEMENT = 25.1;

    std::string contents;
    double weight;

    std::cout << "Enter contents of the sack (C for cement, G for gravel, S for sand): ";
    std::cin >> contents;

    std::cout << "Enter weight of the sack in kilograms: ";
    std::cin >> weight;

    if ((contents == "C" && weight >= MIN_WEIGHT_CEMENT && weight <= MAX_WEIGHT_CEMENT) ||
        ((contents == "G" || contents == "S") && weight >= MIN_WEIGHT_SAND_GRAVEL && weight <= MAX_WEIGHT_SAND_GRAVEL)) {
        std::cout << "Accepted Sack Details:" << std::endl;
        std::cout << "Contents: " << contents << std::endl;
        std::cout << "Weight: " << std::fixed << std::setprecision(2) << weight << " kilograms" << std::endl;
    } else {
        std::cout << "Rejected Sack: ";
        if (contents != "C" && contents != "G" && contents != "S") {
            std::cout << "Invalid contents. ";
        }
        if (weight < MIN_WEIGHT_SAND_GRAVEL || weight > MAX_WEIGHT_SAND_GRAVEL) {
            std::cout << "Invalid weight for sand or gravel. ";
        }
        if (contents == "C" && (weight < MIN_WEIGHT_CEMENT || weight > MAX_WEIGHT_CEMENT)) {
            std::cout << "Invalid weight for cement. ";
        }
        std::cout << std::endl;
    }

    return 0;
}
