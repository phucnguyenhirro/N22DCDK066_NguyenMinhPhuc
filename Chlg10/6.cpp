#include <iostream>
#include <cctype> // For isalpha and tolower

// Function to count the number of vowels in a C-string
int countVowels(const char* str) {
    if (str == nullptr || *str == '\0') {
        return 0; // Empty string or null pointer
    }

    int vowelCount = 0;

    // Use pointer notation to iterate through the C-string
    while (*str != '\0') {
        char lowercaseChar = std::tolower(*str);

        // Check if the character is a vowel
        if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' ||
            lowercaseChar == 'o' || lowercaseChar == 'u') {
            ++vowelCount;
        }

        ++str;
    }

    return vowelCount;
}

// Function to count the number of consonants in a C-string
int countConsonants(const char* str) {
    if (str == nullptr || *str == '\0') {
        return 0; // Empty string or null pointer
    }

    int consonantCount = 0;

    // Use pointer notation to iterate through the C-string
    while (*str != '\0') {
        char lowercaseChar = std::tolower(*str);

        // Check if the character is an alphabet and not a vowel
        if (std::isalpha(*str) && !(lowercaseChar == 'a' || lowercaseChar == 'e' ||
                                    lowercaseChar == 'i' || lowercaseChar == 'o' ||
                                    lowercaseChar == 'u')) {
            ++consonantCount;
        }

        ++str;
    }

    return consonantCount;
}

int main() {
    const int maxSize = 1000; // You can adjust this based on your needs
    char inputString[maxSize];

    // Ask the user to input a string
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    // Call the function to count the number of vowels
    int vowelCount = countVowels(inputString);

    // Call the function to count the number of consonants
    int consonantCount = countConsonants(inputString);

    // Display the results
    std::cout << "Number of vowels: " << vowelCount << std::endl;
    std::cout << "Number of consonants: " << consonantCount << std::endl;

    return 0;
}
