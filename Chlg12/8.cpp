#include <iostream>
#include <string>

const int MAX_SPEAKERS = 10;

// Define the Speaker structure
struct Speaker {
    std::string name;
    std::string phoneNumber;
    std::string speakingTopic;
    double feeRequired;
};

// Function to display the menu
void displayMenu() {
    std::cout << "\nSpeaker's Bureau Menu:\n";
    std::cout << "1. Enter speaker data\n";
    std::cout << "2. Modify speaker data\n";
    std::cout << "3. Display all speakers\n";
    std::cout << "4. Exit\n";
    std::cout << "------------------------\n";
}

// Function to enter speaker data
void enterSpeakerData(Speaker speakers[], int& speakerCount) {
    if (speakerCount < MAX_SPEAKERS) {
        std::cout << "\nEnter speaker data:\n";
        Speaker newSpeaker;
        std::cout << "Name: ";
        std::getline(std::cin >> std::ws, newSpeaker.name);  // Allowing input with spaces
        std::cout << "Telephone Number: ";
        std::getline(std::cin >> std::ws, newSpeaker.phoneNumber);  // Allowing input with spaces
        std::cout << "Speaking Topic: ";
        std::getline(std::cin >> std::ws, newSpeaker.speakingTopic);  // Allowing input with spaces
        std::cout << "Fee Required: $";
        std::cin >> newSpeaker.feeRequired;

        speakers[speakerCount] = newSpeaker;
        ++speakerCount;

        std::cout << "Speaker data entered successfully.\n";
    } else {
        std::cout << "Cannot add more speakers. Maximum limit reached.\n";
    }
}

// Function to modify speaker data
void modifySpeakerData(Speaker speakers[], int speakerCount) {
    if (speakerCount > 0) {
        std::cout << "\nEnter the index of the speaker to modify (0 to " << speakerCount - 1 << "): ";
        int index;
        std::cin >> index;

        if (index >= 0 && index < speakerCount) {
            std::cout << "\nEnter new data for the speaker:\n";
            std::cout << "Name: ";
            std::getline(std::cin >> std::ws, speakers[index].name);  // Allowing input with spaces
            std::cout << "Telephone Number: ";
            std::getline(std::cin >> std::ws, speakers[index].phoneNumber);  // Allowing input with spaces
            std::cout << "Speaking Topic: ";
            std::getline(std::cin >> std::ws, speakers[index].speakingTopic);  // Allowing input with spaces
            std::cout << "Fee Required: $";
            std::cin >> speakers[index].feeRequired;

            std::cout << "Speaker data modified successfully.\n";
        } else {
            std::cout << "Invalid index. Please enter a valid index.\n";
        }
    } else {
        std::cout << "No speakers available to modify.\n";
    }
}

// Function to display all speakers
void displayAllSpeakers(const Speaker speakers[], int speakerCount) {
    if (speakerCount > 0) {
        std::cout << "\nAll Speakers:\n";
        for (int i = 0; i < speakerCount; ++i) {
            std::cout << "Speaker #" << i << ":\n";
            std::cout << "Name: " << speakers[i].name << std::endl;
            std::cout << "Telephone Number: " << speakers[i].phoneNumber << std::endl;
            std::cout << "Speaking Topic: " << speakers[i].speakingTopic << std::endl;
            std::cout << "Fee Required: $" << speakers[i].feeRequired << std::endl;
            std::cout << "------------------------\n";
        }
    } else {
        std::cout << "No speakers available to display.\n";
    }
}

int main() {
    Speaker speakers[MAX_SPEAKERS];
    int speakerCount = 0;
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                enterSpeakerData(speakers, speakerCount);
                break;
            case 2:
                modifySpeakerData(speakers, speakerCount);
                break;
            case 3:
                displayAllSpeakers(speakers, speakerCount);
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
