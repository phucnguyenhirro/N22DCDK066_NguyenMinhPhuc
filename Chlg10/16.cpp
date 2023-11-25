#include <iostream>
#include <sstream>
#include <vector>
#include <cctype> // For isalpha function

// Function to convert a word to Pig Latin
std::string convertToPigLatin(const std::string& word) {
    if (word.empty() || !std::isalpha(word[0])) {
        return word; // Return unchanged if the word is empty or doesn't start with an alphabetic character
    }

    std::string pigLatinWord = word.substr(1) + word[0] + "ay";
    return pigLatinWord;
}

// Function to convert a sentence to Pig Latin
std::string convertSentenceToPigLatin(const std::string& sentence) {
    std::istringstream iss(sentence);
    std::string word;
    std::vector<std::string> pigLatinWords;

    // Read each word from the sentence and convert to Pig Latin
    while (iss >> word) {
        pigLatinWords.push_back(convertToPigLatin(word));
    }

    // Join the Pig Latin words to form the Pig Latin sentence
    std::ostringstream oss;
    for (const auto& pigLatinWord : pigLatinWords) {
        oss << pigLatinWord << ' ';
    }

    return oss.str();
}

int main() {
    std::string userInput;

    // Ask the user to enter a sentence
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, userInput);

    // Convert and display the sentence in Pig Latin
    std::string pigLatinSentence = convertSentenceToPigLatin(userInput);
    std::cout << "Pig Latin: " << pigLatinSentence << std::endl;

    return 0;
}
