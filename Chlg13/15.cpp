#include <iostream>
#include <cmath> // For pow()

class MortgageCalculator {
private:
    double loanAmount;
    double annualInterestRate;
    int loanYears;

public:
    // Default constructor
    MortgageCalculator() : loanAmount(0.0), annualInterestRate(0.0), loanYears(0) {}

    // Setter functions
    void setLoanAmount(double amount) {
        loanAmount = amount;
    }

    void setAnnualInterestRate(double rate) {
        annualInterestRate = rate;
    }

    void setLoanYears(int years) {
        loanYears = years;
    }

    // Function to calculate monthly payment
    double calculateMonthlyPayment() const {
        double monthlyInterestRate = annualInterestRate / 12 / 100;
        int numberOfPayments = loanYears * 12;

        double monthlyPayment = (loanAmount * monthlyInterestRate) /
                                (1 - pow(1 + monthlyInterestRate, -numberOfPayments));

        return monthlyPayment;
    }

    // Function to calculate total amount paid
    double calculateTotalAmountPaid() const {
        return calculateMonthlyPayment() * loanYears * 12;
    }
};

int main() {
    MortgageCalculator mortgage;

    // Get loan details from the user
    double loanAmount, annualInterestRate;
    int loanYears;

    std::cout << "Enter the loan amount: $";
    std::cin >> loanAmount;

    std::cout << "Enter the annual interest rate (in percentage): ";
    std::cin >> annualInterestRate;

    std::cout << "Enter the number of years of the loan: ";
    std::cin >> loanYears;

    // Set loan details in the MortgageCalculator object
    mortgage.setLoanAmount(loanAmount);
    mortgage.setAnnualInterestRate(annualInterestRate);
    mortgage.setLoanYears(loanYears);

    // Display monthly payment and total amount paid
    std::cout << "\nMonthly Payment: $" << mortgage.calculateMonthlyPayment() << std::endl;
    std::cout << "Total Amount Paid: $" << mortgage.calculateTotalAmountPaid() << std::endl;

    return 0;
}
