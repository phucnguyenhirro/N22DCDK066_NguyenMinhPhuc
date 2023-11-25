#include <iostream>
#include <string>

// Define the DivisionData structure
struct DivisionData {
    std::string divisionName;
    double firstQuarterSales;
    double secondQuarterSales;
    double thirdQuarterSales;
    double fourthQuarterSales;
    double totalAnnualSales;
    double averageQuarterlySales;
};

// Function to input sales data for a division
void inputSalesData(DivisionData& division) {
    std::cout << "Enter sales data for division " << division.divisionName << ":\n";
    std::cout << "First Quarter Sales: ";
    std::cin >> division.firstQuarterSales;
    std::cout << "Second Quarter Sales: ";
    std::cin >> division.secondQuarterSales;
    std::cout << "Third Quarter Sales: ";
    std::cin >> division.thirdQuarterSales;
    std::cout << "Fourth Quarter Sales: ";
    std::cin >> division.fourthQuarterSales;

    // Calculate total annual sales and average quarterly sales
    division.totalAnnualSales = division.firstQuarterSales +
                                division.secondQuarterSales +
                                division.thirdQuarterSales +
                                division.fourthQuarterSales;

    division.averageQuarterlySales = division.totalAnnualSales / 4.0;
}

// Function to display sales data for a division
void displayDivisionData(const DivisionData& division) {
    std::cout << "\nDivision: " << division.divisionName << std::endl;
    std::cout << "Total Annual Sales: $" << division.totalAnnualSales << std::endl;
    std::cout << "Average Quarterly Sales: $" << division.averageQuarterlySales << std::endl;
    std::cout << "------------------------\n";
}

int main() {
    // Create variables for each division
    DivisionData eastDivision = {"East"};
    DivisionData westDivision = {"West"};
    DivisionData northDivision = {"North"};
    DivisionData southDivision = {"South"};

    // Input sales data for each division
    inputSalesData(eastDivision);
    inputSalesData(westDivision);
    inputSalesData(northDivision);
    inputSalesData(southDivision);

    // Display sales data for each division
    displayDivisionData(eastDivision);
    displayDivisionData(westDivision);
    displayDivisionData(northDivision);
    displayDivisionData(southDivision);

    return 0;
}
