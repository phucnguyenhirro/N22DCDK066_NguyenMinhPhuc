#include <iostream>
#include <string>

const int NUM_PLAYERS = 2;

// Define the SoccerPlayer structure
struct SoccerPlayer {
    std::string playerName;
    int playerNumber;
    int pointsScored;
};

// Function to input data for a soccer player
void inputPlayerData(SoccerPlayer& player) {
    std::cout << "Enter data for player #" << player.playerNumber << ":\n";
    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, player.playerName);  // Allowing input with spaces
    std::cout << "Number: ";
    std::cin >> player.playerNumber;
    std::cout << "Points Scored: ";
    std::cin >> player.pointsScored;
}

int main() {
    // Create an array of SoccerPlayer structures for each player
    SoccerPlayer team[NUM_PLAYERS];

    // Input data for each player
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        team[i].playerNumber = i + 1; // Player numbers start from 1
        inputPlayerData(team[i]);
    }

    // Display a table of player information
    std::cout << "\nPlayer Table:\n";
    std::cout << "------------------------------------------------\n";
    std::cout << "| Player # | Player Name      | Points Scored |\n";
    std::cout << "------------------------------------------------\n";
    int totalPoints = 0;
    int maxPoints = 0;
    int maxPointsPlayerNumber = 0;
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        std::cout << "|    " << team[i].playerNumber << "     | ";
        std::cout.width(17);
        std::cout << std::left << team[i].playerName << " | ";
        std::cout.width(13);
        std::cout << std::right << team[i].pointsScored << " |\n";
        
        totalPoints += team[i].pointsScored;

        if (team[i].pointsScored > maxPoints) {
            maxPoints = team[i].pointsScored;
            maxPointsPlayerNumber = team[i].playerNumber;
        }
    }
    // std::cout << "------------------------------------------------\n";
    // std::cout << "| Total    |                   | " << std:: setw(13) << totalPoints << " |\n";
    // std::cout << "------------------------------------------------\n";
    // std::cout << "Player #" << maxPointsPlayerNumber << " (" << team[maxPointsPlayerNumber - 1].playerName << ") has earned the most points.\n";

    return 0;
}
