#include <iostream>
#include <string>

// Define the structure for customer account data
struct CustomerAccount {
    std::string name;
    std::string address;
    std::string cityStateZIP;
    std::string telephoneNumber;
    double accountBalance;
    std::string dateOfLastPayment;
};

// Function to display the menu
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Enter new customer data\n";
    std::cout << "2. Change data for an existing customer\n";
    std::cout << "3. Display all customer data\n";
    std::cout << "4. Exit\n";
}

// Function to enter new customer data
void enterNewCustomerData(CustomerAccount& customer) {
    std::cin.ignore(); // Clear the input buffer

    std::cout << "Enter customer name: ";
    std::getline(std::cin, customer.name);

    std::cout << "Enter customer address: ";
    std::getline(std::cin, customer.address);

    std::cout << "Enter city, state, and ZIP: ";
    std::getline(std::cin, customer.cityStateZIP);

    std::cout << "Enter telephone number: ";
    std::getline(std::cin, customer.telephoneNumber);

    do {
        std::cout << "Enter account balance: $";
        std::cin >> customer.accountBalance;

        // Input validation: Check for negative account balance
        if (customer.accountBalance < 0) {
            std::cout << "Account balance cannot be negative. Please enter a valid balance.\n";
        }
    } while (customer.accountBalance < 0);

    std::cin.ignore(); // Clear the input buffer

    std::cout << "Enter date of last payment: ";
    std::getline(std::cin, customer.dateOfLastPayment);

    std::cout << "New customer data entered successfully.\n";
}

// Function to change data for an existing customer
void changeCustomerData(CustomerAccount& customer) {
    std::cin.ignore(); // Clear the input buffer

    std::cout << "Enter new customer name: ";
    std::getline(std::cin, customer.name);

    std::cout << "Enter new customer address: ";
    std::getline(std::cin, customer.address);

    std::cout << "Enter new city, state, and ZIP: ";
    std::getline(std::cin, customer.cityStateZIP);

    std::cout << "Enter new telephone number: ";
    std::getline(std::cin, customer.telephoneNumber);

    do {
        std::cout << "Enter new account balance: $";
        std::cin >> customer.accountBalance;

        // Input validation: Check for negative account balance
        if (customer.accountBalance < 0) {
            std::cout << "Account balance cannot be negative. Please enter a valid balance.\n";
        }
    } while (customer.accountBalance < 0);

    std::cin.ignore(); // Clear the input buffer

    std::cout << "Enter new date of last payment: ";
    std::getline(std::cin, customer.dateOfLastPayment);

    std::cout << "Customer data updated successfully.\n";
}

// Function to display all customer data
void displayAllCustomerData(const CustomerAccount customers[], int numCustomers) {
    std::cout << "\nAll Customer Data:\n";
    std::cout << "---------------------------------------------\n";
    std::cout << "Name\t\tAddress\t\tCity/State/ZIP\t\tTelephone\tAccount Balance\tLast Payment Date\n";
    std::cout << "---------------------------------------------\n";

    for (int i = 0; i < numCustomers; ++i) {
        std::cout << customers[i].name << "\t"
                  << customers[i].address << "\t"
                  << customers[i].cityStateZIP << "\t"
                  << customers[i].telephoneNumber << "\t$"
                  << customers[i].accountBalance << "\t\t"
                  << customers[i].dateOfLastPayment << std::endl;
    }

    std::cout << "---------------------------------------------\n";
}

int main() {
    const int numCustomers = 10;
    CustomerAccount customerAccounts[numCustomers];

    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "\nEnter new customer data:\n";
                enterNewCustomerData(customerAccounts[numCustomers - 1]);
                break;

            case 2:
                std::cout << "\nEnter customer index to change data (1-" << numCustomers << "): ";
                int indexToChange;
                std::cin >> indexToChange;

                if (indexToChange >= 1 && indexToChange <= numCustomers) {
                    std::cout << "\nEnter new data for customer " << indexToChange << ":\n";
                    changeCustomerData(customerAccounts[indexToChange - 1]);
                } else {
                    std::cout << "Invalid index. Please enter a valid index.\n";
                }
                break;

            case 3:
                displayAllCustomerData(customerAccounts, numCustomers);
                break;

            case 4:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid choice (1-4).\n";
        }

    } while (choice != 4);

