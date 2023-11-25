#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <ctime>

// Function to convert the date format
std::string convertDateFormat(const std::string& inputDate) {
    std::tm tm = {};
    std::istringstream iss(inputDate);
    iss >> std::get_time(&tm, "%m/%d/%Y");

    if (iss.fail()) {
        return "Invalid date format. Please use mm/dd/yyyy.";
    }

    std::ostringstream oss;
    oss << std::put_time(&tm, "%B %d, %Y");
    return oss.str();
}

int main() {
    
    std::string userDate;

    // Ask the user to enter a date
    std::cout << "Enter a date in the form mm/dd/yyyy: ";
    std::cin >> userDate;

    // Convert and display the date in the desired format
    std::string formattedDate = convertDateFormat(userDate);
    std::cout << "Formatted date: " << formattedDate << std::endl;

    return 0;
}
