#include <iostream>
#include <cfloat>

class FloatArray {
private:
    float* array;
    int size;

public:
    // Constructor
    FloatArray(int n) {
        size = n;
        array = new float[size];
    }

    // Destructor
    ~FloatArray() {
        delete[] array;
    }

    // Function to store a number in a specific element of the array
    void storeNumber(int index, float value) {
        if (index >= 0 && index < size) {
            array[index] = value;
        } else {
            std::cerr << "Index out of bounds." << std::endl;
        }
    }

    // Function to retrieve a number from a specific element of the array
    float retrieveNumber(int index) const {
        if (index >= 0 && index < size) {
            return array[index];
        } else {
            std::cerr << "Index out of bounds. Returning 0.0." << std::endl;
            return 0.0;
        }
    }

    // Function to return the highest value stored in the array
    float getHighestValue() const {
        float highest = FLT_MIN;
        for (int i = 0; i < size; ++i) {
            if (array[i] > highest) {
                highest = array[i];
            }
        }
        return highest;
    }

    // Function to return the lowest value stored in the array
    float getLowestValue() const {
        float lowest = FLT_MAX;
        for (int i = 0; i < size; ++i) {
            if (array[i] < lowest) {
                lowest = array[i];
            }
        }
        return lowest;
    }

    // Function to return the average of all the numbers stored in the array
    float getAverage() const {
        if (size == 0) {
            std::cerr << "Cannot calculate average for an empty array. Returning 0.0." << std::endl;
            return 0.0;
        }

        float sum = 0.0;
        for (int i = 0; i < size; ++i) {
            sum += array[i];
        }

        return sum / size;
    }
};

int main() {
    // Example usage of the FloatArray class
    int arraySize;
    std::cout << "Enter the size of the array: ";
    std::cin >> arraySize;

    // Create an instance of the FloatArray class
    FloatArray floatArray(arraySize);

    // Store some numbers in the array
    for (int i = 0; i < arraySize; ++i) {
        float value;
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> value;
        floatArray.storeNumber(i, value);
    }

    // Retrieve and display a number from the array
    int indexToRetrieve;
    std::cout << "Enter the index to retrieve: ";
    std::cin >> indexToRetrieve;
    float retrievedValue = floatArray.retrieveNumber(indexToRetrieve);
    std::cout << "Value at index " << indexToRetrieve << ": " << retrievedValue << std::endl;

    // Display highest, lowest, and average values
    std::cout << "Highest value: " << floatArray.getHighestValue() << std::endl;
    std::cout << "Lowest value: " << floatArray.getLowestValue() << std::endl;
    std::cout << "Average value: " << floatArray.getAverage() << std::endl;

    return 0;
}
