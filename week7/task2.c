#include <iostream>
#include <iomanip>
#include <string>

int main() {
    const int NUM_CHARITIES = 3;
    std::string charityNames[NUM_CHARITIES];
    double charityTotals[NUM_CHARITIES] = {0.0, 0.0, 0.0};

    // Input charity names
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        std::cout << "Enter the name of Charity " << (i + 1) << ": ";
        std::getline(std::cin >> std::ws, charityNames[i]);
    }

    while (true) {
        // Display charity names with corresponding numbers
        std::cout << "\nCharities:\n";
        for (int i = 0; i < NUM_CHARITIES; ++i) {
            std::cout << (i + 1) << ". " << charityNames[i] << std::endl;
        }

        // Choose charity (1, 2, or 3)
        int chosenCharity;
        std::cout << "\nEnter the number of the chosen charity (1, 2, or 3) or enter 0 to exit: ";
        std::cin >> chosenCharity;

        if (chosenCharity == 0) {
            break; // Exit loop if 0 is entered
        }

        if (chosenCharity < 1 || chosenCharity > NUM_CHARITIES) {
            std::cout << "Invalid choice. Please choose a valid charity or enter 0 to exit.\n";
            continue; // Restart the loop if an invalid choice is entered
        }

        // Enter shopping bill
        double shoppingBill;
        std::cout << "Enter the customer's shopping bill: $";
        std::cin >> shoppingBill;

        // Calculate donation
        const double DONATION_PERCENTAGE = 0.01;
        double donation = shoppingBill * DONATION_PERCENTAGE;

        // Update charity total
        charityTotals[chosenCharity - 1] += donation;

        // Display donation details
        std::cout << "\nDonation Details:\n";
        std::cout << "Chosen Charity: " << charityNames[chosenCharity - 1] << std::endl;
        std::cout << "Shopping Bill: $" << std::fixed << std::setprecision(2) << shoppingBill << std::endl;
        std::cout << "Donation Amount: $" << std::fixed << std::setprecision(2) << donation << std::endl;
        std::cout << "Total Donation for " << charityNames[chosenCharity - 1] << ": $"
                  << std::fixed << std::setprecision(2) << charityTotals[chosenCharity - 1] << std::endl;
    }

    // Display total donations for all charities
    std::cout << "\nTotal Donations:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        std::cout << charityNames[i] << ": $" << std::fixed << std::setprecision(2) << charityTotals[i] << std::endl;
    }

    return 0;
}
