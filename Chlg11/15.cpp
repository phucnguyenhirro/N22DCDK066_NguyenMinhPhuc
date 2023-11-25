#include <iostream>

// Structure for hourly paid worker
struct HourlyPaid {
    double hoursWorked;
    double hourlyRate;
};

// Structure for salaried worker
struct Salaried {
    double salary;
    double bonus;
};

// Union with structures for both types of workers
union WorkerData {
    HourlyPaid hourlyWorker;
    Salaried salariedWorker;
};

// Function to calculate pay for hourly paid worker
double calculateHourlyPay(const HourlyPaid& worker) {
    return worker.hoursWorked * worker.hourlyRate;
}

// Function to calculate pay for salaried worker
double calculateSalariedPay(const Salaried& worker) {
    return worker.salary + worker.bonus;
}

int main() {
    // Declare a union variable
    WorkerData workerData;

    // Ask the user whether to calculate pay for an hourly paid or salaried worker
    char workerType;
    std::cout << "Enter 'H' for hourly paid worker or 'S' for salaried worker: ";
    std::cin >> workerType;

    // Get input data based on user's choice
    if (workerType == 'H' || workerType == 'h') {
        std::cout << "Enter hours worked: ";
        std::cin >> workerData.hourlyWorker.hoursWorked;

        std::cout << "Enter hourly rate: ";
        std::cin >> workerData.hourlyWorker.hourlyRate;

        // Calculate and display pay for hourly paid worker
        std::cout << "Hourly paid worker pay: $" << calculateHourlyPay(workerData.hourlyWorker) << std::endl;
    } else if (workerType == 'S' || workerType == 's') {
        std::cout << "Enter monthly salary: ";
        std::cin >> workerData.salariedWorker.salary;

        std::cout << "Enter bonus: ";
        std::cin >> workerData.salariedWorker.bonus;

        // Calculate and display pay for salaried worker
        std::cout << "Salaried worker pay: $" << calculateSalariedPay(workerData.salariedWorker) << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 'H' or 'S'." << std::endl;
    }


    return 0;
}
