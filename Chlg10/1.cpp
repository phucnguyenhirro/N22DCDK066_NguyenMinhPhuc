#include <iostream>

// Function to count the number of characters in a C-string
int countCharacters(const char* str) {
    int count = 0;

    // Use pointer notation to iterate through the C-string until the null terminator is encountered
    while (*str != '\0') {
        ++count;
        ++str;
    }

    return count;
}

int main() {
    const int maxSize = 100; // You can adjust this based on your needs
    char inputString[maxSize];

    // Ask the user to input a string
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    // Call the function to count the number of characters
    int charCount = countCharacters(inputString);

    // Display the result
    std::cout << "Number of characters in the string: " << charCount << std::endl;

    return 0;
}
