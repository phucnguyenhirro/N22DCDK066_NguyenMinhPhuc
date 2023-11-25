#include <iostream>
#include <string>
#include <unordered_map>

// Function to find the most frequently occurring character in a C-string or std::string
char mostFrequentCharacter(const char* cStr) {
    if (cStr == nullptr || *cStr == '\0') {
        return '\0'; // Return null character for an empty string or null pointer
    }

    // Using an unordered_map to store the frequency of each character
    std::unordered_map<char, int> charFrequency;

    // Iterate through the characters in the C-string
    while (*cStr != '\0') {
        // Increment the frequency for each character
        charFrequency[*cStr]++;
        ++cStr;
    }

    // Find the character with the maximum frequency
    char mostFrequent = cStr[0]; // Initialize with the first character
    int maxFrequency = charFrequency[cStr[0]];

    for (const auto& entry : charFrequency) {
        if (entry.second > maxFrequency) {
            mostFrequent = entry.first;
            maxFrequency = entry.second;
        }
    }

    return mostFrequent;
}

// Overloaded function to find the most frequently occurring character in a std::string
char mostFrequentCharacter(const std::string& str) {
    if (str.empty()) {
        return '\0'; // Return null character for an empty string
    }

    // Using an unordered_map to store the frequency of each character
    std::unordered_map<char, int> charFrequency;

    // Iterate through the characters in the std::string
    for (char c : str) {
        // Increment the frequency for each character
        charFrequency[c]++;
    }

    // Find the character with the maximum frequency
    char mostFrequent = str[0]; // Initialize with the first character
    int maxFrequency = charFrequency[str[0]];

    for (const auto& entry : charFrequency) {
        if (entry.second > maxFrequency) {
            mostFrequent = entry.first;
            maxFrequency = entry.second;
        }
    }

    return mostFrequent;
}

int main() {
    const int maxSize = 1000; // You can adjust this based on your needs
    char inputCStr[maxSize];
    std::string inputStr;

    // Ask the user to input a string using C-string
    std::cout << "Enter a string using C-string: ";
    std::cin.getline(inputCStr, maxSize);

    // Call the function to find the most frequently occurring character in C-string
    char mostFrequentCStr = mostFrequentCharacter(inputCStr);

    // Display the result for C-string
    std::cout << "Most frequently occurring character (C-string): " << mostFrequentCStr << std::endl;

    // Ask the user to input a string using std::string
    std::cout << "Enter a string using std::string: ";
    std::cin.ignore(); // Ignore the newline character left in the input buffer
    std::getline(std::cin, inputStr);

    // Call the overloaded function to find the most frequently occurring character in std::string
    char mostFrequentStr = mostFrequentCharacter(inputStr);

    // Display the result for std::string
    std::cout << "Most frequently occurring character (std::string): " << mostFrequentStr << std::endl;

    return 0;
}
