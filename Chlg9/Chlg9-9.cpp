#include <iostream>

// Function to determine the median of a sorted array
double findMedian(const int* arr, int size) {
    if (size <= 0) {
        return -1; // Invalid size
    }

    // Use pointer notation to get the middle element(s)
    const int* middle = arr + size / 2;

    // Check if the array has an even number of elements
    if (size % 2 == 0) {
        // If even, calculate the average of the two middle elements
        const int* middleMinusOne = middle - 1;
        return static_cast<double>(*middle + *middleMinusOne) / 2.0;
    } else {
        // If odd, return the middle element
        return static_cast<double>(*middle);
    }
}

int main() {
    const int size = 6;
    int arr[size] = {1, 2, 3, 4, 5, 6};

    double median = findMedian(arr, size);

    if (median != -1) {
        std::cout << "The median of the array is: " << median << std::endl;
    } else {
        std::cout << "Invalid array size." << std::endl;
    }

    return 0;
}
