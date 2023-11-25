#include <iostream>

// Function to create a reversed copy of an integer array
int* reverseArray(const int* arr, int size) {
    if (size <= 0) {
        return nullptr; // Invalid size
    }

    // Allocate memory for the reversed array
    int* reversedArray = new int[size];

    // Use pointer notation to copy and reverse the array
    for (int i = 0; i < size; ++i) {
        reversedArray[i] = arr[size - 1 - i];
    }

    return reversedArray;
}

// Function to display an integer array
void displayArray(const int* arr, int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int size = 5;
    int originalArray[size] = {1, 2, 3, 4, 5};

    // Display the original array
    displayArray(originalArray, size);

    // Create a reversed copy of the array
    int* reversedArray = reverseArray(originalArray, size);

    // Display the reversed array
    displayArray(reversedArray, size);

    // Deallocate the memory for the reversed array
    delete[] reversedArray;

    return 0;
}
