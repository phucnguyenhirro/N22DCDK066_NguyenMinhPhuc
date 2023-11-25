#include <iostream>
#include <string>

const int NUM_CUSTOMERS = 10;

// Define the Customer structure
struct Customer {
    std::string name;
    std::string address;
    double balance;
};

// Function to input data for a customer
void inputCustomerData(Customer& customer) {
    std::cout << "Enter data for the customer:\n";
    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, customer.name);  // Allowing input with spaces
    std::cout << "Address: ";
    std::getline(std::cin >> std::ws, customer.address);  // Allowing input with spaces
    std::cout << "Balance: $";
    std::cin >> customer.balance;
}

// Function to display data for a customer
void displayCustomerData(const Customer& customer) {
    std::cout << "Name: " << customer.name << std::endl;
    std::cout << "Address: " << customer.address << std::endl;
    std::cout << "Balance: $" << customer.balance << std::endl;
    std::cout << "------------------------\n";
}

// Function to search for customer accounts by name
void searchAccountsByName(const Customer customers[], int numCustomers, const std::string& searchName) {
    bool found = false;

    std::cout << "\nSearch Results for Customers with Name containing \"" << searchName << "\":\n";
    for (int i = 0; i < numCustomers; ++i) {
        if (customers[i].name.find(searchName) != std::string::npos) {
            displayCustomerData(customers[i]);
            found = true;
        }
    }

    if (!found) {
        std::cout << "No accounts found for the specified name.\n";
    }
}

int main() {
    // Create an array of Customer structures
    Customer accounts[NUM_CUSTOMERS];

    // Input data for each customer
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        inputCustomerData(accounts[i]);
    }

    // Display data for each customer
    std::cout << "\nCustomer Data:\n";
    for (int i = 0; i < NUM_CUSTOMERS; ++i) {
        displayCustomerData(accounts[i]);
    }

    // Search for customer accounts by name
    std::string searchName;
    std::cout << "\nEnter part of the customer's name to search: ";
    std::getline(std::cin >> std::ws, searchName);  // Allowing input with spaces

    searchAccountsByName(accounts, NUM_CUSTOMERS, searchName);

    return 0;
}
