#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

struct Charity {
    std::string name;
    double total;
};

bool compareCharities(const Charity& a, const Charity& b) {
    return a.total > b.total;
}

int main() {
    const int NUM_CHARITIES = 3;
    std::vector<Charity> charities(NUM_CHARITIES, {"", 0.0});
    double grandTotal = 0.0;

    while (true) {
        // Display charity names with corresponding numbers
        std::cout << "\nCharities:\n";
        for (int i = 0; i < NUM_CHARITIES; ++i) {
            std::cout << (i + 1) << ". " << charities[i].name << std::endl;
        }
        std::cout << "Enter the number of the chosen charity (1, 2, or 3), enter -1 to show totals, or enter 0 to exit: ";

        int chosenCharity;
        std::cin >> chosenCharity;

        if (chosenCharity == 0) {
            break; // Exit loop if 0 is entered
        } else if (chosenCharity == -1) {
            // Display totals in descending order
            std::sort(charities.begin(), charities.end(), compareCharities);

            std::cout << "\nCharity Totals (Descending Order):\n";
            for (const auto& charity : charities) {
                std::cout << charity.name << ": $" << std::fixed << std::setprecision(2) << charity.total << std::endl;
            }

            // Display grand total
            std::cout << "\nGRAND TOTAL DONATED TO CHARITY: $" << std::fixed << std::setprecision(2) << grandTotal << std::endl;
            continue; // Restart the loop without processing donation for -1
        } else if (chosenCharity < 1 || chosenCharity > NUM_CHARITIES) {
            std::cout << "Invalid choice. Please choose a valid charity, enter -1 to show totals, or enter 0 to exit.\n";
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
        charities[chosenCharity - 1].total += donation;
        grandTotal += donation;

        // Display donation details
        std::cout << "\nDonation Details:\n";
        std::cout << "Chosen Charity: " << charities[chosenCharity - 1].name << std::endl;
        std::cout << "Shopping Bill: $" << std::fixed << std::setprecision(2) << shoppingBill << std::endl;
        std::cout << "Donation Amount: $" << std::fixed << std::setprecision(2) << donation << std::endl;
        std::cout << "Total Donation for " << charities[chosenCharity - 1].name << ": $"
                  << std::fixed << std::setprecision(2) << charities[chosenCharity - 1].total << std::endl;
    }

    return 0;
}
