#include <iostream>

// Function to perform descending order bubble sort
void bubbleSortDescending(double arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Swap elements if they are in the wrong order
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void displayDonations(const double arr[], int size) {
    std::cout << "Sorted Donation values in descending order:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Donation " << i + 1 << ": " << arr[i] << std::endl;
    }
}

int main() {
    // Assume arrptr is the array you want to sort
    const int size = 5; // You should replace this with the actual size of your array
    double arrptr[size] = {5.0, 3.0, 8.0, 1.0, 2.0}; // Replace this with your actual array

    // Call the descending order sorting function
    bubbleSortDescending(arrptr, size);

    // Display sorted donations in descending order
    displayDonations(arrptr, size);

    return 0;
}
