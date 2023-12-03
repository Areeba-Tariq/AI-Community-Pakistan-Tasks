#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int BASIC_SET_COST = 200;
const double DISCOUNT_PERCENTAGE_1_ITEM = 5.0;
const double DISCOUNT_PERCENTAGE_2_OR_MORE_ITEMS = 10.0;
const vector<string> itemCodes = {"A1", "A2", "B1", "B2", "B3", "C1", "C2", "C3", "D1", "D2", "E1", "E2", "E3", "F1", "F2", "G1", "G2"};
const vector<string> descriptions = {"Compact", "Tower", "8 GB", "16 GB", "32 GB", "1 TB HDD", "2 TB HDD", "4 TB HDD", "240 GB SSD",
        "480 GB SSD", "1 TB HDD", "DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer", "Standard Version", "Professional Version"};
const vector<double> prices = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99, 129.99, 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00};

string chooseItem(string category);
bool isValidItemCode(string itemCode, string category);
string getItemCategory(string itemCode);
void displayItems(string category);
double calculateTotalPrice(string caseItem, string ramItem, string hddItem);
double getPrice(string itemCode);
void displayOrderDetails(string caseItem, string ramItem, string hddItem, double totalPrice);
string getDescription(string itemCode);
bool getYesOrNoInput(string prompt);
void chooseAdditionalItems(double& totalPrice);
void displayOrderDetails(double totalPrice);

int main() {
    cout << "Welcome to the Online Computer Shop!" << endl;
    
    cout << "\nTask 1 - Setting up the system and ordering the main items" << endl;
    string caseItem = chooseItem("Case");
    string ramItem = chooseItem("RAM");
    string hddItem = chooseItem("Main Hard Disk Drive");
    double totalPrice = calculateTotalPrice(caseItem, ramItem, hddItem);
    
    displayOrderDetails(caseItem, ramItem, hddItem, totalPrice);
    
    cout << "\nTask 2 - Ordering additional items" << endl;
    bool additionalItems = getYesOrNoInput("Would you like to purchase additional items?");
    if (additionalItems) {
        chooseAdditionalItems(totalPrice);
    }
    
    cout << "\nTask 3 - Offering discounts" << endl;
    // applyDiscount(totalPrice);
    
    return 0;
}

string chooseItem(string category) {
    cout << "\nChoose a " << category << ":" << endl;
    displayItems(category);
    string userChoice;
    do {
        cout << "Enter the item code: ";
        cin >> userChoice;
        
        if (!isValidItemCode(userChoice, category)) {
            cout << "Invalid item code. Please try again." << endl;
        }
    } while (!isValidItemCode(userChoice, category));
    return userChoice;
}

bool isValidItemCode(string itemCode, string category) {
    for (int i = 0; i < itemCodes.size(); i++) {
        if (itemCodes[i] == itemCode && getItemCategory(itemCode) == category) {
            return true;
        }
    }
    return false;
}

string getItemCategory(string itemCode) {
    char categoryCode = itemCode[0];
    switch (categoryCode) {
        case 'A':
            return "Case";
        case 'B':
            return "RAM";
        case 'C':
            return "Main Hard Disk Drive";
        
        default:
            return "Unknown";
    }
}

void displayItems(string category) {
    cout << "Item Code\tDescription\t\tPrice ($)" << endl;
    for (int i = 0; i < itemCodes.size(); i++) {
        if (getItemCategory(itemCodes[i]) == category) {
            cout << itemCodes[i] << "\t\t" << descriptions[i] << "\t\t\t" << prices[i] << endl;
        }
    }
}

double calculateTotalPrice(string caseItem, string ramItem, string hddItem) {
    double totalPrice = BASIC_SET_COST;
    totalPrice += getPrice(caseItem) + getPrice(ramItem) + getPrice(hddItem);
    return totalPrice;
}

double getPrice(string itemCode) {
    for (int i = 0; i < itemCodes.size(); i++) {
        if (itemCodes[i] == itemCode) {
            return prices[i];
        }
    }
    return 0.0;
}

void displayOrderDetails(string caseItem, string ramItem, string hddItem, double totalPrice) {
    cout << "\nOrder Details:" << endl;
    cout << "Case:\t\t" << getDescription(caseItem) << endl;
    cout << "RAM:\t\t" << getDescription(ramItem) << endl;
    cout << "Main HDD:\t" << getDescription(hddItem) << endl;
    cout << "Total Price:\t$" << totalPrice << endl;
}

string getDescription(string itemCode) {
    for (int i = 0; i < itemCodes.size(); i++) {
        if (itemCodes[i] == itemCode) {
            return descriptions[i];
        }
    }
    return "Unknown";
}

bool getYesOrNoInput(string prompt) {
    cout << prompt << " (yes/no): ";
    string userInput;
    do {
        cin >> userInput;
        if (userInput == "yes") {
            return true;
        } else if (userInput == "no") {
            return false;
        } else {
            cout << "Invalid input. Please enter 'yes' or 'no': ";
        }
    } while (true);
}

void chooseAdditionalItems(double& totalPrice) {
    bool choosingItems = true;
    while (choosingItems) {
        cout << "\nChoose additional items:" << endl;
        displayItems("Additional Items");
        string userChoice;
        do {
            cout << "Enter the item code (or type 'done' to finish): ";
            cin >> userChoice;
            if (userChoice == "done") {
                choosingItems = false;
            } else if (!isValidItemCode(userChoice, "Additional Items")) {
                cout << "Invalid item code. Please try again." << endl;
            }
        } while (userChoice != "done" && !isValidItemCode(userChoice, "Additional Items"));
        if (userChoice != "done") {
            totalPrice += getPrice(userChoice);
            cout << getDescription(userChoice) << " added to the order." << endl;
        }
    }
    
    displayOrderDetails(totalPrice);
}

void displayOrderDetails(double totalPrice) {
    cout << "\nUpdated Order Details:" << endl;
    // Display order details
}


