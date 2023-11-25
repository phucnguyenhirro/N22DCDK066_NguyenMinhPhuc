#include <iostream>

// Function to display the contents of a C-string backward
void displayBackward(const char* str) {
    if (str == nullptr) {
        std::cout << "Invalid C-string pointer." << std::endl;
        return;
    }

    // Use pointer notation to find the end of the string
    const char* endPtr = str;
    while (*endPtr != '\0') {
        ++endPtr;
    }

    // Use pointer notation to iterate backward through the string and display its contents
    while (endPtr != str) {
        --endPtr;
        std::cout << *endPtr;
    }

    // Display a newline at the end
    std::cout << std::endl;
}

int main() {
    const int maxSize = 100; // You can adjust this based on your needs
    char inputString[maxSize];

    // Ask the user to input a string
    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxSize);

    // Call the function to display the contents backward
    std::cout << "String backward: ";
    displayBackward(inputString);

    return 0;
}
