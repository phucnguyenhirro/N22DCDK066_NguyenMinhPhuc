#include <iostream>
#include <string>

class Employee {
private:
    std::string name;
    int idNumber;
    std::string department;
    std::string position;

public:
    // Constructors
    Employee(std::string empName, int empId, std::string empDept, std::string empPosition)
        : name(empName), idNumber(empId), department(empDept), position(empPosition) {}

    Employee(std::string empName, int empId)
        : name(empName), idNumber(empId), department(""), position("") {}

    Employee()
        : name(""), idNumber(0), department(""), position("") {}

    // Mutator functions
    void setName(std::string empName) {
        name = empName;
    }

    void setIdNumber(int empId) {
        idNumber = empId;
    }

    void setDepartment(std::string empDept) {
        department = empDept;
    }

    void setPosition(std::string empPosition) {
        position = empPosition;
    }

    // Accessor functions
    std::string getName() const {
        return name;
    }

    int getIdNumber() const {
        return idNumber;
    }

    std::string getDepartment() const {
        return department;
    }

    std::string getPosition() const {
        return position;
    }
};

int main() {
    // Create three Employee objects
    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee emp2("Mark Jones", 39119, "IT", "Programmer");
    Employee emp3("Joy Rogers", 81774);

    // Set department and position for emp3
    emp3.setDepartment("Manufacturing");
    emp3.setPosition("Engineer");

    // Display data for each employee
    std::cout << "Employee 1:\n";
    std::cout << "Name: " << emp1.getName() << "\n";
    std::cout << "ID Number: " << emp1.getIdNumber() << "\n";
    std::cout << "Department: " << emp1.getDepartment() << "\n";
    std::cout << "Position: " << emp1.getPosition() << "\n\n";

    std::cout << "Employee 2:\n";
    std::cout << "Name: " << emp2.getName() << "\n";
    std::cout << "ID Number: " << emp2.getIdNumber() << "\n";
    std::cout << "Department: " << emp2.getDepartment() << "\n";
    std::cout << "Position: " << emp2.getPosition() << "\n\n";

    std::cout << "Employee 3:\n";
    std::cout << "Name: " << emp3.getName() << "\n";
    std::cout << "ID Number: " << emp3.getIdNumber() << "\n";
    std::cout << "Department: " << emp3.getDepartment() << "\n";
    std::cout << "Position: " << emp3.getPosition() << "\n";

    return 0;
}
