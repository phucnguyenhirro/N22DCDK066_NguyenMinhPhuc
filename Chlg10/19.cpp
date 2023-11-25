#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

// Function to convert a number to words
std::string convertToWords(double amount) {
    static const std::string units[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    static const std::string teens[] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    static const std::string tens[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    std::string result;

    int dollars = static_cast<int>(amount);
    int cents = static_cast<int>((amount - dollars) * 100);

    // Convert dollars to words
    if (dollars >= 1000) {
        result += units[dollars / 1000] + " Thousand ";
        dollars %= 1000;
    }

    if (dollars >= 100) {
        result += units[dollars / 100] + " Hundred ";
        dollars %= 100;
    }

    if (dollars >= 20) {
        result += tens[dollars / 10] + " ";
        dollars %= 10;
    }

    if (dollars >= 10) {
        result += teens[dollars - 10] + " ";
    } else if (dollars > 0) {
        result += units[dollars] + " ";
    }

    // Convert cents to words
    result += "and " + std::to_string(cents) + " cents";

    return result;
}

int main() {
    std::string date, payee;
    double amount;

    // Get user input
    std::cout << "Enter the date: ";
    std::getline(std::cin, date);

    std::cout << "Enter the payee's name: ";
    std::getline(std::cin, payee);

    do {
        std::cout << "Enter the amount of the check (up to $10,000): ";
        std::cin >> amount;

        // Input validation
        if (amount < 0 || amount > 10000) {
            std::cout << "Invalid amount. Please enter a non-negative amount up to $10,000." << std::endl;
        }
    } while (amount < 0 || amount > 10000);

    // Display the simulated paycheck
    std::cout << "\nDate: " << date << std::endl;
    std::cout << "Pay to the Order of: " << payee << " $" << std::fixed << std::setprecision(2) << amount << std::endl;
    std::cout << convertToWords(amount) << std::endl;

    return 0;
}
