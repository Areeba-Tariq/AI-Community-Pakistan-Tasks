#include <iostream>
#include <iomanip>

int main() {
    const int NUM_BOATS = 10;
    const double HOUR_RATE = 20.0;
    const double HALF_HOUR_RATE = 12.0;
    const int OPENING_TIME = 10;
    const int CLOSING_TIME = 17;

    double moneyTaken = 0.0;
    int totalHoursHired = 0;

    for (int boatNumber = 1; boatNumber <= NUM_BOATS; ++boatNumber) {
        std::cout << "\nBoat #" << boatNumber << ":\n";

        // Get start time
        int startTime;
        std::cout << "Enter the start time (between 10 and 17): ";
        std::cin >> startTime;

        if (startTime < OPENING_TIME || startTime >= CLOSING_TIME) {
            std::cout << "Invalid start time. Boat cannot be hired before 10:00 or after 17:00.\n";
            continue; // Move to the next boat
        }

        // Get duration
        int duration;
        std::cout << "Enter the duration in hours: ";
        std::cin >> duration;

        if (startTime + duration > CLOSING_TIME) {
            std::cout << "Invalid duration. Boat cannot be returned after 17:00.\n";
            continue; // Move to the next boat
        }

        // Calculate cost
        double cost;
        if (duration == 1) {
            cost = HOUR_RATE;
        } else if (duration == 0.5) {
            cost = HALF_HOUR_RATE;
        } else {
            std::cout << "Invalid duration. Duration can only be 0.5 or 1 hour.\n";
            continue; // Move to the next boat
        }

        // Update totals
        moneyTaken += cost;
        totalHoursHired += duration;

        // Display details for the boat
        std::cout << "Money taken for Boat #" << boatNumber << ": $" << std::fixed << std::setprecision(2) << cost << std::endl;
        std::cout << "Total hours hired for Boat #" << boatNumber << ": " << totalHoursHired << " hours\n";
    }

    // Display total for the day
    std::cout << "\nTotal money taken for the day: $" << std::fixed << std::setprecision(2) << moneyTaken << std::endl;
    std::cout << "Total hours hired for all boats: " << totalHoursHired << " hours\n";

    return 0;
}
