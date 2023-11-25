#include <iostream>
#include <iomanip>

struct Student {
    std::string name;
    int idnum;
    int* tests;
    double average;
    char grade;
};

// Function to calculate the average test score
double calculateAverage(int* tests, int numTests) {
    double sum = 0;
    for (int i = 0; i < numTests; ++i) {
        sum += tests[i];
    }
    return (numTests == 0) ? 0 : (sum / numTests);
}

// Function to calculate the course grade based on the grading scale
char calculateGrade(double average) {
    if (average >= 91) return 'A';
    else if (average >= 81) return 'B';
    else if (average >= 71) return 'C';
    else if (average >= 61) return 'D';
    else return 'F';
}

// Function to input student data
void inputStudentData(Student& student, int numTests) {
    std::cout << "Enter student name: ";
    std::getline(std::cin, student.name);

    std::cout << "Enter student ID number: ";
    std::cin >> student.idnum;

    student.tests = new int[numTests];
    for (int i = 0; i < numTests; ++i) {
        std::cout << "Enter test score " << i + 1 << " for " << student.name << ": ";
        std::cin >> student.tests[i];
    }

    student.average = calculateAverage(student.tests, numTests);
    student.grade = calculateGrade(student.average);
}

// Function to display student data
void displayStudentData(const Student& student) {
    std::cout << std::left << std::setw(20) << student.name
              << std::setw(10) << student.idnum
              << std::setw(15) << std::fixed << std::setprecision(2) << student.average
              << std::setw(5) << student.grade << std::endl;
}

int main() {
    int numTests, numStudents;

    std::cout << "Enter the number of test scores: ";
    std::cin >> numTests;

    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    // Dynamically allocate an array of structures
    Student* students = new Student[numStudents];

    // Input data for each student
    for (int i = 0; i < numStudents; ++i) {
        std::cin.ignore(); // Clear the newline character from the buffer
        inputStudentData(students[i], numTests);
    }

    // Display header
    std::cout << std::left << std::setw(20) << "Name"
              << std::setw(10) << "ID Number"
              << std::setw(15) << "Average"
              << std::setw(5) << "Grade" << std::endl;
    
    // Display student data
    for (int i = 0; i < numStudents; ++i) {
        displayStudentData(students[i]);
    }

    // Deallocate dynamically allocated memory
    for (int i = 0; i < numStudents; ++i) {
        delete[] students[i].tests;
    }
    delete[] students;

    return 0;
}
