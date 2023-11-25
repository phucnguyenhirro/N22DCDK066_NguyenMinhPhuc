#include <iostream>
#include <string>

int main() {
    std::string userInput;

    // Ask the user to enter a series of single-digit numbers
    std::cout << "Enter a series of single-digit numbers with no spaces: ";
    std::cin >> userInput;

    int sum = 0;
    char highestDigit = '0';
    char lowestDigit = '9';

    // Iterate through the characters in the string
    for (char digit : userInput) {
        if (isdigit(digit)) {
            int numericValue = digit - '0';

            // Update the sum
            sum += numericValue;

            // Update the highest and lowest digits
            if (digit > highestDigit) {
                highestDigit = digit;
            }

            if (digit < lowestDigit) {
                lowestDigit = digit;
            }
        } else {
            // Ignore non-digit characters
            std::cout << "Ignoring non-digit character: " << digit << std::endl;
        }
    }

    // Display the results
    std::cout << "Sum of single-digit numbers: " << sum << std::endl;
    std::cout << "Highest digit: " << highestDigit << std::endl;
    std::cout << "Lowest digit: " << lowestDigit << std::endl;

    return 0;
}
