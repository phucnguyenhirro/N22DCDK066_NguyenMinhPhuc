#include <iostream>
#include <cctype> // For character functions

bool isPasswordValid(const std::string& password) {
    // Check if the password is at least six characters long
    if (password.length() < 6) {
        std::cout << "Password should be at least six characters long." << std::endl;
        return false;
    }

    // Check if the password contains at least one uppercase and one lowercase letter
    bool hasUppercase = false;
    bool hasLowercase = false;

    for (char ch : password) {
        if (std::isupper(ch)) {
            hasUppercase = true;
        } else if (std::islower(ch)) {
            hasLowercase = true;
        }

        // Break the loop if both conditions are satisfied
        if (hasUppercase && hasLowercase) {
            break;
        }
    }

    if (!hasUppercase || !hasLowercase) {
        std::cout << "Password should contain at least one uppercase and one lowercase letter." << std::endl;
        return false;
    }

    // Check if the password has at least one digit
    bool hasDigit = false;

    for (char ch : password) {
        if (std::isdigit(ch)) {
            hasDigit = true;
            break; // Break the loop if a digit is found
        }
    }

    if (!hasDigit) {
        std::cout << "Password should have at least one digit." << std::endl;
        return false;
    }

    // If all criteria are met, the password is valid
    return true;
}

int main() {
    std::string userPassword;

    // Ask the user to enter a password
    std::cout << "Enter your password: ";
    std::cin >> userPassword;

    // Validate the password
    if (isPasswordValid(userPassword)) {
        std::cout << "Password is valid. Welcome!" << std::endl;
    } else {
        std::cout << "Password is invalid. Please follow the specified criteria." << std::endl;
    }

    return 0;
}
