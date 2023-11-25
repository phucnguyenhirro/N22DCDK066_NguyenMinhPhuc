#include <iostream>

void getDonations(double*& donations, int& size) {
    std::cout << "Enter the number of donations: ";
    std::cin >> size;

    // Dynamically allocate an array for donations
    donations = new double[size];

    std::cout << "Enter the donation values:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Donation " << i + 1 << ": ";
        std::cin >> donations[i];
    }
}

void displayDonations(const double* donations, int size) {
    std::cout << "Donation values:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Donation " << i + 1 << ": " << donations[i] << std::endl;
    }
}

void deallocateDonations(double*& donations) {
    delete[] donations;
    donations = nullptr;
}

int main() {
    double* donations = nullptr;
    int size;

    // Get donations from the user
    getDonations(donations, size);

    // Display donations
    displayDonations(donations, size);

    // Deallocate dynamically allocated memory
    deallocateDonations(donations);

    return 0;
}
