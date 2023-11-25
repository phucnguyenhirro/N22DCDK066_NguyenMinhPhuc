#include <iostream>
#include <cstring> // For C-string functions
#include <string>  // For string class

// Function to count the number of words and calculate the average number of letters in a C-string
void countWordsAndAverage(const char* str, int& wordCount, double& averageLetters) {
    if (str == nullptr || *str == '\0') {
        wordCount = 0;
        averageLetters = 0.0;
        return; // Empty string or null pointer
    }

    int totalLetters = 0;
    wordCount = 1; // Initialize with 1 to account for the first word

    // Use pointer notation to iterate through the C-string
    while (*str != '\0') {
        // Increment word count when a space is encountered
        if (*str == ' ') {
            ++wordCount;
        } else {
            // Increment letter count for each non-space character
            ++totalLetters;
        }
        ++str;
    }

    // Calculate the average number of letters
    if (wordCount > 0) {
        averageLetters = static_cast<double>(totalLetters) / wordCount;
    } else {
        averageLetters = 0.0;
    }
}

// Overloaded function to count the number of words and calculate the average number of letters in a string class object
void countWordsAndAverage(const std::string& str, int& wordCount, double& averageLetters) {
    if (str.empty()) {
        wordCount = 0;
        averageLetters = 0.0;
        return; // Empty string
    }

    int totalLetters = 0;
    wordCount = 1; // Initialize with 1 to account for the first word

    // Use iterator to iterate through the string
    for (auto it = str.begin(); it != str.end(); ++it) {
        // Increment word count when a space is encountered
        if (*it == ' ') {
            ++wordCount;
        } else {
            // Increment letter count for each non-space character
            ++totalLetters;
        }
    }

    // Calculate the average number of letters
    if (wordCount > 0) {
        averageLetters = static_cast<double>(totalLetters) / wordCount;
    } else {
        averageLetters = 0.0;
    }
}

int main() {
    const int maxSize = 100; // You can adjust this based on your needs
    char inputString[maxSize];

    // Ask the user to input a string
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    int wordCountCStr;
    double averageLettersCStr;

    // Call the function to count the number of words and calculate the average for the C-string
    countWordsAndAverage(inputString, wordCountCStr, averageLettersCStr);

    // Display the result for C-string
    std::cout << "Number of words in the C-string: " << wordCountCStr << std::endl;
    std::cout << "Average number of letters in each word: " << averageLettersCStr << std::endl;

    // Ask the user to input a string using std::string
    std::string inputStringClass;
    std::cout << "Enter a string using std::string: ";
    std::getline(std::cin, inputStringClass);

    int wordCountStrClass;
    double averageLettersStrClass;

    // Call the overloaded function to count the number of words and calculate the average for the std::string
    countWordsAndAverage(inputStringClass, wordCountStrClass, averageLettersStrClass);

    // Display the result for std::string
    std::cout << "Number of words in the std::string: " << wordCountStrClass << std::endl;
    std::cout << "Average number of letters in each word: " << averageLettersStrClass << std::endl;

    return 0;
}
