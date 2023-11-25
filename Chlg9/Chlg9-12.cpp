#include <iostream>

// Function to create a new array that is twice the size of the input array
int* doubleSizeArray(const int* arr, int size) {
    if (size <= 0) {
        return nullptr; // Invalid size
    }

    // Allocate memory for the new array (twice the size of the input array)
    int* newArray = new int[2 * size];

    // Use pointer notation to copy the contents of the input array
    for (int i = 0; i < size; ++i) {
        newArray[i] = arr[i];
    }

    // Initialize the remaining elements with 0
    for (int i = size; i < 2 * size; ++i) {
        newArray[i] = 0;
    }

    return newArray;
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
    const int size = 3;
    int originalArray[size] = {1, 2, 3};

    // Display the original array
    displayArray(originalArray, size);

    // Create a new array that is twice the size of the original array
    int* newArray = doubleSizeArray(originalArray, size);

    // Display the new array
    displayArray(newArray, 2 * size);

    // Deallocate the memory for the new array
    delete[] newArray;

    return 0;
}
