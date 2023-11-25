#include <iostream>
#include <fstream>
#include <cctype> // For isupper and islower functions

int main() {
    std::ifstream inputFile("text.txt");

    // Check if the file is successfully opened
    if (!inputFile) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    char ch;
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;

    // Read each character from the file
    while (inputFile.get(ch)) {
        if (std::isupper(ch)) {
            uppercaseCount++;
        } else if (std::islower(ch)) {
            lowercaseCount++;
        } else if (std::isdigit(ch)) {
            digitCount++;
        }
    }

    // Display the results
    std::cout << "Number of uppercase letters: " << uppercaseCount << std::endl;
    std::cout << "Number of lowercase letters: " << lowercaseCount << std::endl;
    std::cout << "Number of digits: " << digitCount << std::endl;

    // Close the file
    inputFile.close();

    return 0;
}
