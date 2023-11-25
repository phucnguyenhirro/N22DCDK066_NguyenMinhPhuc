#include <iostream>
#include <string>

// Function to replace all occurrences of string2 with string3 in string1
std::string replaceSubstring(const std::string& string1, const std::string& string2, const std::string& string3) {
    std::string result = string1;

    // Find the first occurrence of string2 in string1
    size_t foundPos = result.find(string2);

    // Iterate until no more occurrences are found
    while (foundPos != std::string::npos) {
        // Replace the occurrence with string3
        result.replace(foundPos, string2.length(), string3);

        // Find the next occurrence of string2 in the modified string
        foundPos = result.find(string2, foundPos + string3.length());
    }

    return result;
}

int main() {
    std::string inputString1, inputString2, inputString3;

    // Ask the user to input three strings
    std::cout << "Enter the first string: ";
    std::getline(std::cin, inputString1);

    std::cout << "Enter the second string to replace: ";
    std::getline(std::cin, inputString2);

    std::cout << "Enter the replacement string: ";
    std::getline(std::cin, inputString3);

    // Call the function to replace occurrences
    std::string resultString = replaceSubstring(inputString1, inputString2, inputString3);

    // Display the result
    std::cout << "Resulting string: " << resultString << std::endl;

    return 0;
}
