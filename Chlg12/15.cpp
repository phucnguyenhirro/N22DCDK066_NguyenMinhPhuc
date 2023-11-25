#include <iostream>

// Define the HourlyPaid structure
struct HourlyPaid {
    double hoursWorked;
    double hourlyRate;
};

// Define the Salaried structure
struct Salaried {
    double salary;
    double bonus;
};

// Define the PayData union
union PayData {
    HourlyPaid hourlyPaidData;
    Salaried salariedData;
};

// Function to calculate pay for an hourly paid worker
double calculateHourlyPay(const HourlyPaid& hourlyData) {
    return hourlyData.hoursWorked * hourlyData.hourlyRate;
}

// Function to calculate pay for a salaried worker
double calculateSalariedPay(const Salaried& salariedData) {
    return salariedData.salary + salariedData.bonus;
}

int main() {
    // Declare a union with two members for hourly paid and salaried workers
    union Payroll {
        HourlyPaid hourlyWorker;
        Salaried salariedWorker;
    };

    // Declare a variable of the union type
    Payroll employeeData;

    // Declare a variable to store the user's choice
    char workerType;

    // Ask the user whether to calculate pay for an hourly paid or salaried worker
    std::cout << "Enter 'H' for hourly paid worker or 'S' for salaried worker: ";
    std::cin >> workerType;

    // Prompt the user for the appropriate data based on the worker type
    if (workerType == 'H' || workerType == 'h') {
        std::cout << "Enter hours worked: ";
        std::cin >> employeeData.hourlyWorker.hoursWorked;

        std::cout << "Enter hourly rate: $";
        std::cin >> employeeData.hourlyWorker.hourlyRate;

        // Calculate and display the pay for an hourly paid worker
        double hourlyPay = calculateHourlyPay(employeeData.hourlyWorker);
        std::cout << "Hourly paid worker's pay: $" << hourlyPay << std::endl;
    } else if (workerType == 'S' || workerType == 's') {
        std::cout << "Enter salary: $";
        std::cin >> employeeData.salariedWorker.salary;

        std::cout << "Enter bonus: $";
        std::cin >> employeeData.salariedWorker.bonus;

        // Calculate and display the pay for a salaried worker
        double salariedPay = calculateSalariedPay(employeeData.salariedWorker);
        std::cout << "Salaried worker's pay: $" << salariedPay << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 'H' or 'S'." << std::endl;
    }

    return 0;
}

