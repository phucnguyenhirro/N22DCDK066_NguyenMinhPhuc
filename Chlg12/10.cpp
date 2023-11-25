#include <iostream>
#include <string>

// Define the MonthlyBudget structure
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
void enterBudgetData(MonthlyBudget& budget) {
    std::cout << "Enter the amounts spent in each budget category:\n";
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

// Function to display a report indicating the amount over or under in each category
void displayBudgetReport(const MonthlyBudget& budget) {
    double totalBudget = 500.0 + 150.0 + 65.0 + 50.0 + 250.0 + 30.0 + 100.0 + 150.0 + 75.0 + 50.0;
    double totalSpent = budget.housing + budget.utilities + budget.householdExpenses +
                        budget.transportation + budget.food + budget.medical +
                        budget.insurance + budget.entertainment + budget.clothing + budget.miscellaneous;

    std::cout << "\nBudget Report:\n";
    std::cout << "------------------------\n";
    std::cout << "Category              | Budget   | Spent    | Difference\n";
    std::cout << "------------------------\n";
    std::cout << "Housing               | $500.00  | $" << budget.housing << "     | $" << budget.housing - 500.0 << "\n";
    std::cout << "Utilities             | $150.00  | $" << budget.utilities << "     | $" << budget.utilities - 150.0 << "\n";
    std::cout << "Household Expenses    | $65.00   | $" << budget.householdExpenses << "     | $" << budget.householdExpenses - 65.0 << "\n";
    std::cout << "Transportation        | $50.00   | $" << budget.transportation << "     | $" << budget.transportation - 50.0 << "\n";
    std::cout << "Food                  | $250.00  | $" << budget.food << "     | $" << budget.food - 250.0 << "\n";
    std::cout << "Medical               | $30.00   | $" << budget.medical << "     | $" << budget.medical - 30.0 << "\n";
    std::cout << "Insurance             | $100.00  | $" << budget.insurance << "     | $" << budget.insurance - 100.0 << "\n";
    std::cout << "Entertainment         | $150.00  | $" << budget.entertainment << "     | $" << budget.entertainment - 150.0 << "\n";
    std::cout << "Clothing              | $75.00   | $" << budget.clothing << "     | $" << budget.clothing - 75.0 << "\n";
    std::cout << "Miscellaneous         | $50.00   | $" << budget.miscellaneous << "     | $" << budget.miscellaneous - 50.0 << "\n";
    std::cout << "------------------------\n";
    std::cout << "Total Budget          | $" << totalBudget << " | Total Spent | $" << totalSpent << " | Total Difference | $" << totalSpent - totalBudget << "\n";
    std::cout << "------------------------\n";
}

int main() {
    MonthlyBudget monthlyBudget;

    // Input amounts spent in each budget category
    enterBudgetData(monthlyBudget);

    // Display a report indicating the amount over or under in each category
    displayBudgetReport(monthlyBudget);

    return 0;
}
