#include <iostream>
#include <string>

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructor
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    // Member function to print the date in the format MM/DD/YYYY
    void printFormat1() const {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }

    // Member function to print the date in the format Month DD, YYYY
    void printFormat2() const {
        std::string monthNames[] = {
            "", "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };

        std::cout << monthNames[month] << " " << day << ", " << year << std::endl;
    }

    // Member function to print the date in the format DD Month YYYY
    void printFormat3() const {
        std::string monthNames[] = {
            "", "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };

        std::cout << day << " " << monthNames[month] << " " << year << std::endl;
    }
};

int main() {
    // Create a Date object with the date 12/25/2014
    Date myDate(12, 25, 2014);

    // Print the date in different formats
    std::cout << "Format 1: ";
    myDate.printFormat1();

    std::cout << "Format 2: ";
    myDate.printFormat2();

    std::cout << "Format 3: ";
    myDate.printFormat3();

    return 0;
}
