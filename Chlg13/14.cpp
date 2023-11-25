#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Die class for simulating die rolls
class Die {
private:
    int sides;

public:
    // Constructor
    Die(int numSides) : sides(numSides) {
        // Seed for random number generation
        srand(static_cast<unsigned int>(time(0)));
    }

    // Function to roll the die
    int roll() const {
        return rand() % sides + 1;
    }
};

int main() {
    // Create an instance of the Die class with 6 sides
    Die die(6);

    // Variables for user input and fishing points
    char continueFishing;
    int fishingPoints = 0;

    // Game loop
    do {
        // Ask the user if they want to continue fishing
        std::cout << "Do you want to fish for more items? (y/n): ";
        std::cin >> continueFishing;

        // Roll the die to determine the caught item
        int dieResult = die.roll();

        // Determine fishing points based on the caught item
        switch (dieResult) {
            case 1:
                std::cout << "You caught a huge fish! (+5 points)" << std::endl;
                fishingPoints += 5;
                break;
            case 2:
                std::cout << "You caught an old shoe! (+1 point)" << std::endl;
                fishingPoints += 1;
                break;
            case 3:
                std::cout << "You caught a little fish! (+2 points)" << std::endl;
                fishingPoints += 2;
                break;
            // Add more cases for other possible items
            // ...
            default:
                std::cout << "Invalid die result." << std::endl;
                break;
        }

    } while (continueFishing == 'y' || continueFishing == 'Y');

    // Display total fishing points and congratulate the user
    std::cout << "Total fishing points: " << fishingPoints << std::endl;

    if (fishingPoints >= 10) {
        std::cout << "Congratulations! You're a master angler!" << std::endl;
    } else if (fishingPoints >= 5) {
        std::cout << "Well done! You've caught some good fish!" << std::endl;
    } else {
        std::cout << "Better luck next time. Keep practicing!" << std::endl;
    }

    return 0;
}
