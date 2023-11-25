#include <iostream>
#include <cstring> // For C-string functions

int main() {
    const int maxSize = 100; // You can adjust this based on your needs

    char firstName[maxSize];
    char middleName[maxSize];
    char lastName[maxSize];
    char arrangedName[maxSize * 3]; // The size is set to accommodate the formatted name

    // Ask the user to input their first, middle, and last names
    std::cout << "Enter your first name: ";
    std::cin.getline(firstName, maxSize);

    std::cout << "Enter your middle name: ";
    std::cin.getline(middleName, maxSize);

    std::cout << "Enter your last name: ";
    std::cin.getline(lastName, maxSize);

    // Construct the formatted name in the fourth array
    std::strcpy(arrangedName, lastName);
    std::strcat(arrangedName, ", ");
    std::strcat(arrangedName, firstName);
    std::strcat(arrangedName, " ");
    std::strcat(arrangedName, middleName);

    // Display the formatted name
    std::cout << "Formatted name: " << arrangedName << std::endl;

    return 0;
}
