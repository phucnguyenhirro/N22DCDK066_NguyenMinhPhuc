#include <iostream>
#include <algorithm> // For sorting

// Function prototypes
void inputNameAndScores(std::string* names, int* scores, int size);
void sortNameAndScores(std::string* names, int* scores, int size);
void displayResults(const std::string* names, const int* scores, int size);

int main() {
    int size;

    // Get the number of students from the user
    std::cout << "Enter the number of students: ";
    std::cin >> size;

    // Check for valid size
    if (size <= 0) {
        std::cout << "Invalid size. Exiting program." << std::endl;
        return 1;
    }

    // Dynamically allocate arrays to hold student names and scores
    std::string* studentNames = new std::string[size];
    int* studentScores = new int[size];

    // Input student names and scores
    inputNameAndScores(studentNames, studentScores, size);

    // Sort student names and scores
    sortNameAndScores(studentNames, studentScores, size);

    // Display results
    displayResults(studentNames, studentScores, size);

    // Deallocate the dynamically allocated memory
    delete[] studentNames;
    delete[] studentScores;

    return 0;
}

void inputNameAndScores(std::string* names, int* scores, int size) {
    std::cout << "Enter name-score pairs for each student:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Student " << i + 1 << " Name: ";
        std::cin >> names[i];

        do {
            std::cout << "Student " << i + 1 << " Score: ";
            std::cin >> scores[i];

            // Input validation: Do not accept negative numbers
            if (scores[i] < 0) {
                std::cout << "Invalid input. Please enter a non-negative number." << std::endl;
            }
        } while (scores[i] < 0);
    }
}

void sortNameAndScores(std::string* names, int* scores, int size) {
    // Use the sort function from the algorithm header
    // Sort based on scores, and rearrange names accordingly
    std::sort(scores, scores + size);
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (scores[i] == scores[j]) {
                std::swap(names[i], names[j]);
            }
        }
    }
}

void displayResults(const std::string* names, const int* scores, int size) {
    std::cout << "\nSorted List of Scores with Names:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Student Name: " << names[i] << ", Score: " << scores[i] << std::endl;
    }
}
