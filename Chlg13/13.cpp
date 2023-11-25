#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

class Coin {
private:
    std::string sideUp;

public:
    // Default constructor
    Coin() {
        toss(); // Toss the coin when it is created
    }

    // Function to simulate the tossing of the coin
    void toss() {
        // Initialize random seed based on current time
        srand(static_cast<unsigned int>(time(0)));

        // Generate a random number (0 or 1)
        int randomNumber = rand() % 2;

        // Set sideUp based on the random number
        if (randomNumber == 0) {
            sideUp = "heads";
        } else {
            sideUp = "tails";
        }
    }

    // Function to get the value of sideUp
    std::string getSideUp() const {
        return sideUp;
    }
};

int main() {
    // Create instances of Coin for quarter, dime, and nickel
    Coin quarter, dime, nickel;

    // Starting balance
    double balance = 0.0;

    // Play the game until the balance reaches $1 or more
    while (balance < 1.0) {
        // Toss the coins
        quarter.toss();
        dime.toss();
        nickel.toss();

        // Check if the coins landed heads-up and update the balance
        if (quarter.getSideUp() == "heads") {
            balance += 0.25;
        }

        if (dime.getSideUp() == "heads") {
            balance += 0.10;
        }

        if (nickel.getSideUp() == "heads") {
            balance += 0.05;
        }

        // Display the results of the toss
        std::cout << "Quarter: " << quarter.getSideUp() << " ";
        std::cout << "Dime: " << dime.getSideUp() << " ";
        std::cout << "Nickel: " << nickel.getSideUp() << " ";
        std::cout << "Balance: $" << balance << std::endl;
    }

    // Check if the player won or lost
    if (balance == 1.0) {
        std::cout << "Congratulations! You won the game!" << std::endl;
    } else {
        std::cout << "Sorry! You lost the game. Your balance exceeded $1." << std::endl;
    }

    return 0;
}
