#include <iostream>
#include <iomanip>
#include <vector>

struct Boat {
    int boatNumber;
    double moneyTaken;
    int totalHoursHired;
    int returnTime;
};

int main() {
    const int NUM_BOATS = 10;
    const double HOUR_RATE = 20.0;
    const double HALF_HOUR_RATE = 12.0;
    const int OPENING_TIME = 10;
    const int CLOSING_TIME = 17;

    std::vector<Boat> boats(NUM_BOATS);

    // Simulate boat hires for the day
    for (auto& boat : boats) {
        int startTime = OPENING_TIME + rand() % (CLOSING_TIME - OPENING_TIME);
        int duration = rand() % 2 == 0 ? 0.5 : 1;

        if (startTime + duration > CLOSING_TIME) {
            duration = 0.5; // Reduce duration if the boat cannot be returned before closing time
        }

        double cost = duration == 1 ? HOUR_RATE : HALF_HOUR_RATE;

        boat.moneyTaken += cost;
        boat.totalHoursHired += duration;
        boat.returnTime = startTime + duration;

        std::cout << "Boat #" << boat.boatNumber << ": Hired for " << duration << " hours, Cost: $" << cost
                  << ", Total Hours Hired: " << boat.totalHoursHired << ", Return Time: " << boat.returnTime << ":00\n";
    }

    // Calculate totals and find unused and most used boats
    double totalMoneyTaken = 0.0;
    int totalHoursHired = 0;
    int unusedBoats = 0;
    int mostUsedBoatNumber = 0;
    int maxHoursHired = 0;

    for (const auto& boat : boats) {
        totalMoneyTaken += boat.moneyTaken;
        totalHoursHired += boat.totalHoursHired;

        if (boat.totalHoursHired == 0) {
            ++unusedBoats;
        }

        if (boat.totalHoursHired > maxHoursHired) {
            mostUsedBoatNumber = boat.boatNumber;
            maxHoursHired = boat.totalHoursHired;
        }
    }

    // Display end-of-day report
    std::cout << "\nEnd-of-Day Report:\n";
    std::cout << "Total money taken for all boats: $" << std::fixed << std::setprecision(2) << totalMoneyTaken << std::endl;
    std::cout << "Total hours hired for all boats: " << totalHoursHired << " hours\n";
    std::cout << "Number of boats not used: " << unusedBoats << std::endl;
    std::cout << "Boat #" << mostUsedBoatNumber << " was used the most with " << maxHoursHired << " hours.\n";

    return 0;
}
