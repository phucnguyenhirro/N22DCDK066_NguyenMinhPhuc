#include <iostream>
#include <iomanip>

// Define the Drink structure
struct Drink {
    std::string name;
    double cost;
    int quantity;
};

// Function to display the list of drinks
void displayDrinks(const Drink drinks[], int numDrinks) {
    std::cout << "\nDrinks Available:\n";
    for (int i = 0; i < numDrinks; ++i) {
        std::cout << i + 1 << ". " << std::setw(12) << drinks[i].name << " - $" << drinks[i].cost;
        if (drinks[i].quantity > 0) {
            std::cout << " (Quantity: " << drinks[i].quantity << ")\n";
        } else {
            std::cout << " (Sold Out)\n";
        }
    }
    std::cout << "0. Quit\n";
}

// Function to simulate the soft drink machine
void simulateSoftDrinkMachine(Drink drinks[], int numDrinks) {
    double totalEarnings = 0.0;

    while (true) {
        displayDrinks(drinks, numDrinks);

        int choice;
        std::cout << "Enter your choice (0 to quit): ";
        std::cin >> choice;

        if (choice < 0 || choice > numDrinks) {
            std::cout << "Invalid choice. Please enter a valid option.\n";
            continue;
        }

        if (choice == 0) {
            std::cout << "Quitting the program. Total earnings: $" << totalEarnings << "\n";
            break;
        }

        int quantity = drinks[choice - 1].quantity;
        if (quantity > 0) {
            double insertedMoney;
            std::cout << "Enter the amount of money to insert: $";
            std::cin >> insertedMoney;

            if (insertedMoney >= drinks[choice - 1].cost) {
                double change = insertedMoney - drinks[choice - 1].cost;
                totalEarnings += drinks[choice - 1].cost;
                drinks[choice - 1].quantity--;
                std::cout << "Dispensing " << drinks[choice - 1].name << "...\n";
                std::cout << "Change: $" << std::fixed << std::setprecision(2) << change << "\n";
            } else {
                std::cout << "Insufficient funds. Please insert more money.\n";
            }
        } else {
            std::cout << "Sorry, " << drinks[choice - 1].name << " is sold out.\n";
        }
    }
}

int main() {
    const int numDrinks = 5;
    Drink drinks[numDrinks] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };

    simulateSoftDrinkMachine(drinks, numDrinks);

    return 0;
}
