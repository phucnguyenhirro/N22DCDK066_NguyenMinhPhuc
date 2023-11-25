#include <iostream>
#include <string>

// Define the structure for speaker data
struct Speaker {
    std::string name;
    std::string telephoneNumber;
    std::string speakingTopic;
    double fee;
};

// Function to display the menu
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Enter new speaker data\n";
    std::cout << "2. Change data for an existing speaker\n";
    std::cout << "3. Search for a speaker by topic\n";
    std::cout << "4. Display all speaker data\n";
    std::cout << "5. Exit\n";
}

// Function to enter new speaker data
void enterNewSpeakerData(Speaker& speaker) {
    std::cin.ignore(); // Clear the input buffer

    std::cout << "Enter speaker name: ";
    std::getline(std::cin, speaker.name);

    std::cout << "Enter telephone number: ";
    std::getline(std::cin, speaker.telephoneNumber);

    std::cout << "Enter speaking topic: ";
    std::getline(std::cin, speaker.speakingTopic);

    do {
        std::cout << "Enter speaking fee: $";
        std::cin >> speaker.fee;

        // Input validation: Check for negative fee
        if (speaker.fee < 0) {
            std::cout << "Speaking fee cannot be negative. Please enter a valid fee.\n";
        }
    } while (speaker.fee < 0);

    std::cout << "New speaker data entered successfully.\n";
}

// Function to change data for an existing speaker
void changeSpeakerData(Speaker& speaker) {
    std::cin.ignore(); // Clear the input buffer

    std::cout << "Enter new speaker name: ";
    std::getline(std::cin, speaker.name);

    std::cout << "Enter new telephone number: ";
    std::getline(std::cin, speaker.telephoneNumber);

    std::cout << "Enter new speaking topic: ";
    std::getline(std::cin, speaker.speakingTopic);

    do {
        std::cout << "Enter new speaking fee: $";
        std::cin >> speaker.fee;

        // Input validation: Check for negative fee
        if (speaker.fee < 0) {
            std::cout << "Speaking fee cannot be negative. Please enter a valid fee.\n";
        }
    } while (speaker.fee < 0);

    std::cout << "Speaker data updated successfully.\n";
}

// Function to search for a speaker by topic
void searchSpeakerByTopic(const Speaker speakers[], int numSpeakers, const std::string& keyword) {
    bool found = false;

    std::cout << "\nSpeakers with the topic \"" << keyword << "\":\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "Name\t\tTelephone\t\tSpeaking Topic\t\tFee\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < numSpeakers; ++i) {
        // Check if the keyword is found in the speakingTopic
        if (speakers[i].speakingTopic.find(keyword) != std::string::npos) {
            std::cout << speakers[i].name << "\t"
                      << speakers[i].telephoneNumber << "\t"
                      << speakers[i].speakingTopic << "\t\t$"
                      << speakers[i].fee << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No speaker found with the specified topic.\n";
    }

    std::cout << "---------------------------------------------\n";
}

// Function to display all speaker data
void displayAllSpeakerData(const Speaker speakers[], int numSpeakers) {
    std::cout << "\nAll Speaker Data:\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "Name\t\tTelephone\t\tSpeaking Topic\t\tFee\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < numSpeakers; ++i) {
        std::cout << speakers[i].name << "\t"
                  << speakers[i].telephoneNumber << "\t"
                  << speakers[i].speakingTopic << "\t\t$"
                  << speakers[i].fee << std::endl;
    }

    std::cout << "---------------------------------------------\n";
}

int main() {
    const int numSpeakers = 10;
    Speaker speakerArray[numSpeakers];

    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nEnter new speaker data:\n";
                enterNewSpeakerData(speakerArray[numSpeakers - 1]);
                break;

            case 2:
                std::cout << "\nEnter speaker index to change data (1-" << numSpeakers << "): ";
                int indexToChange;
                std::cin >> indexToChange;

                if (indexToChange >= 1 && indexToChange <= numSpeakers) {
                    std::cout << "\nEnter new data for speaker " << indexToChange << ":\n";
                    changeSpeakerData(speakerArray[indexToChange - 1]);
                } else {
                    std::cout << "Invalid index. Please enter a valid index.\n";
                }
                break;

            // case 3:
            //     std::cin.ignore(); // Clear the input buffer
            //     std::cout << "\nEnter topic keyword to search: ";
            //     std::string topicKeyword;
            //     std::getline(std::cin, topicKeyword);
            //     searchSpeakerByTopic(speakerArray, numSpeakers, topicKeyword);
            //     break;

            case 4:
                displayAllSpeakerData(speakerArray, numSpeakers);
                break;

            case 5:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid choice (1-5).\n";
        }

    } while (choice != 5);

    return 0;
}
