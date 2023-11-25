#include <iostream>
#include <cstring> // For C-string functions

// Function to reverse the case of each character in a C-string
void reverse(char* str) {
    while (*str != '\0') {
        if (std::isupper(*str)) {
            *str = std::tolower(*str);
        } else if (std::islower(*str)) {
            *str = std::toupper(*str);
        }
        ++str;
    }
}

// Function to convert each character in a C-string to lowercase
void lower(char* str) {
    while (*str != '\0') {
        *str = std::tolower(*str);
        ++str;
    }
}

// Function to convert each character in a C-string to uppercase
void upper(char* str) {
    while (*str != '\0') {
        *str = std::toupper(*str);
        ++str;
        
    }
}

int main() {
    const int maxSize = 100; // You can adjust this based on your needs
    char inputString[maxSize];

    // Ask the user to input a string
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    // Apply the transformations in the specified order
    reverse(inputString); // Reverse the case
    lower(inputString);   // Convert to lowercase
    upper(inputString);   // Convert to uppercase

    // Display the transformed string
    std::cout << "Transformed string: " << inputString << std::endl;

    return 0;
}
