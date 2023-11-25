#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

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
    // Create instances of the Die class for computer and player dice
    Die computerDie(6);
    Die playerDie(6);

    // Variables for computer and player points
    int computerPoints = 0;
    int playerPoints = 0;

    // Loop for each round of the game
    char rollAgain;
    do {
        // Computer's turn
        int computerRoll = computerDie.roll();
        computerPoints += computerRoll;
        std::cout << "Computer rolls: " << computerRoll << std::endl;

        // Player's turn
        int playerRoll = playerDie.roll();
        playerPoints += playerRoll;
        std::cout << "You roll: " << playerRoll << std::endl;

        // Ask the player if they want to roll again
        std::cout << "Do you want to roll again? (y/n): ";
        std::cin >> rollAgain;

    } while (rollAgain == 'y' || rollAgain == 'Y' && playerPoints <= 21);

    // Display computer's total points
    std::cout << "\nComputer's total points: " << computerPoints << std::endl;

    // Determine the winner
    if (computerPoints > 21 && playerPoints > 21) {
        std::cout << "It's a tie! Both the computer and you went over 21." << std::endl;
    } else if (computerPoints > 21) {
        std::cout << "Computer busts! You win!" << std::endl;
    } else if (playerPoints > 21) {
        std::cout << "You bust! Computer wins!" << std::endl;
    } else if (computerPoints > playerPoints) {
        std::cout << "Computer wins!" << std::endl;
    } else if (playerPoints > computerPoints) {
        std::cout << "You win!" << std::endl;
    } else {
        std::cout << "It's a tie! Both the computer and you have the same points." << std::endl;
    }

    return 0;
}


