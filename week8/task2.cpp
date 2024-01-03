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

    int currentTime;
    std::cout << "Enter the current time: ";
    std::cin >> currentTime;

    if (currentTime < OPENING_TIME || currentTime >= CLOSING_TIME) {
        std::cout << "Invalid current time. Boats cannot be hired before 10:00 or after 17:00.\n";
        return 1;
    }

    // Check boat availability and find the earliest available time
    int earliestAvailableTime = CLOSING_TIME;
    int availableBoats = 0;

    for (auto& boat : boats) {
        std::cout << "\nBoat #" << boat.boatNumber << ":\n";

        if (boat.returnTime <= currentTime) {
            std::cout << "Boat is available for hire now.\n";
            ++availableBoats;
        } else {
            std::cout << "Boat will be available for hire at " << boat.returnTime << ":00.\n";
            earliestAvailableTime = std::min(earliestAvailableTime, boat.returnTime);
        }
    }

    // Display availability information
    if (availableBoats > 0) {
        std::cout << "\nNumber of boats available for hire: " << availableBoats << std::endl;
    } else {
        std::cout << "\nNo boats available for hire. Earliest available time is at " << earliestAvailableTime << ":00.\n";
    }

    return 0;
}
