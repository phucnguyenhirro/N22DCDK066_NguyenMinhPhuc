#include <iostream>
#include <cctype> // For isupper function

// Function to convert the sentence format
std::string convertSentenceFormat(const std::string& inputSentence) {
    std::string outputSentence;
    bool newWord = true; // Flag to track the start of a new word

    for (char ch : inputSentence) {
        if (newWord) {
            outputSentence += std::toupper(ch); // Convert the first character of the word to uppercase
            newWord = false;
        } else {
            if (std::isupper(ch)) {
                outputSentence += ' '; // Add a space before an uppercase letter
            }
            outputSentence += std::tolower(ch); // Convert the remaining characters to lowercase
        }

        // Update the flag for the next iteration
        newWord = (ch == ' '); // Set to true if a space is encountered, indicating the start of a new word
    }

    return outputSentence;
}

int main() {
    
    std::string userInput;

    // Ask the user to enter a sentence
    std::cout << "Enter a sentence with words run together: ";
    std::getline(std::cin, userInput);

    // Convert and display the sentence in the desired format
    std::string formattedSentence = convertSentenceFormat(userInput);
    std::cout << "Formatted sentence: " << formattedSentence << std::endl;

    return 0;
}
