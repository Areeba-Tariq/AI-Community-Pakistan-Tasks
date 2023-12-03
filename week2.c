#include <iostream>
#include <vector>

const int NUM_JOURNEYS = 4;
const int NUM_COACHES = 6;
const int SEATS_PER_COACH = 80;
const double TICKET_PRICE = 25.0;
const int GROUP_DISCOUNT_THRESHOLD = 10;

struct TrainJourney {
    int availableSeats;
    int passengers;
    double revenue;
};

class MountainRailway {
public:
    MountainRailway() {
        upTrains.resize(NUM_JOURNEYS);
        downTrains.resize(NUM_JOURNEYS);
    }

    void startOfDay() {
        for (int i = 0; i < NUM_JOURNEYS; ++i) {
            upTrains[i].availableSeats = NUM_COACHES * SEATS_PER_COACH;
            upTrains[i].passengers = 0;
            upTrains[i].revenue = 0.0;
            downTrains[i].availableSeats = NUM_COACHES * SEATS_PER_COACH;
            downTrains[i].passengers = 0;
            downTrains[i].revenue = 0.0;
        }
    }

    bool purchaseTickets() {
        int upTrainIndex, downTrainIndex, numPassengers;
        std::cout << "Enter the index of the up train (0-3): ";
        std::cin >> upTrainIndex;
        if (upTrainIndex < 0 || upTrainIndex >= NUM_JOURNEYS) {
            std::cerr << "Invalid train index." << std::endl;
            return false;
        }
        std::cout << "Enter the index of the down train (0-3): ";
        std::cin >> downTrainIndex;
        if (downTrainIndex < 0 || downTrainIndex >= NUM_JOURNEYS) {
            std::cerr << "Invalid train index." << std::endl;
            return false;
        }
        std::cout << "Enter the number of passengers: ";
        std::cin >> numPassengers;
        if (numPassengers < 1 || numPassengers > SEATS_PER_COACH * NUM_COACHES) {
            std::cerr << "Invalid number of passengers." << std::endl;
            return false;
        }
        if (numPassengers > upTrains[upTrainIndex].availableSeats ||
                numPassengers > downTrains[downTrainIndex].availableSeats) {
            std::cerr << "Not enough seats available." << std::endl;
            return false;
        }
        upTrains[upTrainIndex].availableSeats -= numPassengers;
        downTrains[downTrainIndex].availableSeats -= numPassengers;
        double totalPrice = numPassengers * TICKET_PRICE;
        if (numPassengers >= GROUP_DISCOUNT_THRESHOLD) {
            int freeTickets = numPassengers / GROUP_DISCOUNT_THRESHOLD;
            totalPrice -= freeTickets * TICKET_PRICE;
        }
        upTrains[upTrainIndex].revenue += totalPrice;
        downTrains[downTrainIndex].revenue += totalPrice;
        upTrains[upTrainIndex].passengers += numPassengers;
        downTrains[downTrainIndex].passengers += numPassengers;
        std::cout << "Tickets purchased successfully!" << std::endl;
        return true;
    }

    void endOfDaySummary() {
        std::cout << "\nEnd of the Day Summary\n" << std::endl;
        std::cout << "Up-Trains:" << std::endl;
        for (int i = 0; i < NUM_JOURNEYS; ++i) {
            std::cout << "Train " << i << ": Passengers: " << upTrains[i].passengers
                      << ", Revenue: $" << upTrains[i].revenue
                      << ", Available Seats: " << upTrains[i].availableSeats << std::endl;
        }
        std::cout << "\nDown-Trains:" << std::endl;
        for (int i = 0; i < NUM_JOURNEYS; ++i) {
            std::cout << "Train " << i << ": Passengers: " << downTrains[i].passengers
                      << ", Revenue: $" << downTrains[i].revenue
                      << ", Available Seats: " << downTrains[i].availableSeats << std::endl;
        }
        int totalPassengers = 0;
        double totalRevenue = 0.0;
        for (int i = 0; i < NUM_JOURNEYS; ++i) {
            totalPassengers += upTrains[i].passengers + downTrains[i].passengers;
            totalRevenue += upTrains[i].revenue + downTrains[i].revenue;
        }
        std::cout << "\nTotal Passengers: " << totalPassengers << std::endl;
        std::cout << "Total Revenue: $" << totalRevenue << std::endl;
    }

private:
    std::vector<TrainJourney> upTrains;
    std::vector<TrainJourney> downTrains;
};

int main() {
    MountainRailway railway;
    railway.startOfDay();
    while (true) {
        std::cout << "\nOptions:\n"
                  << "1. Purchase Tickets\n"
                  << "2. End of the Day Summary\n"
                  << "3. Exit" << std::endl;
        std::cout << "Enter your choice (1-3): ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                if (!railway.purchaseTickets()) {
                    std::cerr << "Ticket purchase failed. Please try again." << std::endl;
                }
                break;
            case 2:
                railway.endOfDaySummary();
                break;
            case 3:
                std::cout << "Exiting program. Have a nice day!" << std::endl;
                return 0;
            default:
                std::cerr << "Invalid choice. Please enter a number between 1 and 3." << std::endl;
        }
    }
}


