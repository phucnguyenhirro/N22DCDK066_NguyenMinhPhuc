#include <iostream>
#include <string>

// Define the structure for company division data
struct DivisionData {
    std::string divisionName;
    double firstQuarterSales;
    double secondQuarterSales;
    double thirdQuarterSales;
    double fourthQuarterSales;
    double totalAnnualSales;
    double averageQuarterlySales;
};

// Function to calculate total and average sales for a division
void calculateSales(DivisionData& division) {
    division.totalAnnualSales = division.firstQuarterSales + division.secondQuarterSales +
                                division.thirdQuarterSales + division.fourthQuarterSales;
    division.averageQuarterlySales = division.totalAnnualSales / 4.0;
}

// Function to get sales figures from the user for a division
void getSalesFigures(DivisionData& division) {
    do {
        std::cout << "Enter the sales figures for " << division.divisionName << " division:\n";
        std::cout << "First Quarter: ";
        std::cin >> division.firstQuarterSales;

        std::cout << "Second Quarter: ";
        std::cin >> division.secondQuarterSales;

        std::cout << "Third Quarter: ";
        std::cin >> division.thirdQuarterSales;

        std::cout << "Fourth Quarter: ";
        std::cin >> division.fourthQuarterSales;

        // Input validation: Check for negative sales figures
        if (division.firstQuarterSales < 0 || division.secondQuarterSales < 0 ||
            division.thirdQuarterSales < 0 || division.fourthQuarterSales < 0) {
            std::cout << "Sales figures cannot be negative. Please enter valid sales figures.\n";
        }
    } while (division.firstQuarterSales < 0 || division.secondQuarterSales < 0 ||
             division.thirdQuarterSales < 0 || division.fourthQuarterSales < 0);
}

// Function to display division data
void displayDivisionData(const DivisionData& division) {
    std::cout << "\nDivision Name: " << division.divisionName << std::endl;
    std::cout << "Total Annual Sales: $" << division.totalAnnualSales << std::endl;
    std::cout << "Average Quarterly Sales: $" << division.averageQuarterlySales << std::endl;
    std::cout << "-------------------------\n";
}

int main() {
    // Create variables for each corporate division
    DivisionData eastDivision = {"East"};
    DivisionData westDivision = {"West"};
    DivisionData northDivision = {"North"};
    DivisionData southDivision = {"South"};

    // Get sales figures from the user for each division
    getSalesFigures(eastDivision);
    getSalesFigures(westDivision);
    getSalesFigures(northDivision);
    getSalesFigures(southDivision);

    // Calculate total and average sales for each division
    calculateSales(eastDivision);
    calculateSales(westDivision);
    calculateSales(northDivision);
    calculateSales(southDivision);

    // Display division data
    displayDivisionData(eastDivision);
    displayDivisionData(westDivision);
    displayDivisionData(northDivision);
    displayDivisionData(southDivision);

    return 0;
}
