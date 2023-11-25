#include <iostream>
#include <iomanip>

// Structure to hold monthly budget categories
struct MonthlyBudget {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

// Function to input amounts spent in each budget category
void inputExpenses(MonthlyBudget& budget) {
    std::cout << "Enter amounts spent in each budget category for the month:\n";

    std::cout << "Housing: ";
    std::cin >> budget.housing;

    std::cout << "Utilities: ";
    std::cin >> budget.utilities;

    std::cout << "Household Expenses: ";
    std::cin >> budget.householdExpenses;

    std::cout << "Transportation: ";
    std::cin >> budget.transportation;

    std::cout << "Food: ";
    std::cin >> budget.food;

    std::cout << "Medical: ";
    std::cin >> budget.medical;

    std::cout << "Insurance: ";
    std::cin >> budget.insurance;

    std::cout << "Entertainment: ";
    std::cin >> budget.entertainment;

    std::cout << "Clothing: ";
    std::cin >> budget.clothing;

    std::cout << "Miscellaneous: ";
    std::cin >> budget.miscellaneous;
}

// Function to display the budget report
void displayBudgetReport(const MonthlyBudget& budget) {
    // Original budget amounts
    const double originalBudget[] = {500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00};

    // Display header
    std::cout << "\nBudget Category\t\tOriginal Budget\t\tAmount Spent\t\tOver/Under\n";
    std::cout << "-------------------------------------------------------------------\n";

    double totalOverUnder = 0.0;

    // Display each budget category and the over/under amount
    for (int i = 0; i < 10; ++i) {
        double overUnder = originalBudget[i] - budget.housing;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::left << std::setw(20) << std::setfill(' ') << std::fixed << std::setprecision(2) << std::left << std::setw(20);

        std::cout << std::fixed << std::setprecision(2) << std::left << std::setw(20) << std::setfill(' ') << overUnder << "\n";

        totalOverUnder += overUnder;
    }

    // Display total over/under amount for the entire monthly budget
    std::cout << "\nTotal Over/Under for the Monthly Budget: $" << totalOverUnder << "\n";
}

int main() {
    MonthlyBudget userBudget;

    // Input amounts spent in each budget category
    inputExpenses(userBudget);

    // Display budget report
    displayBudgetReport(userBudget);

    return 0;
}
