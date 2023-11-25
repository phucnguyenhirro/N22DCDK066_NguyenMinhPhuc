#include <iostream>
#include <string>

class Question {
private:
    std::string questionText;
    std::string answer1;
    std::string answer2;
    std::string answer3;
    std::string answer4;
    int correctAnswer;

public:
    // Constructor
    Question(std::string text, std::string a1, std::string a2, std::string a3, std::string a4, int correct)
        : questionText(text), answer1(a1), answer2(a2), answer3(a3), answer4(a4), correctAnswer(correct) {}

    // Accessor functions
    std::string getQuestionText() const {
        return questionText;
    }

    std::string getAnswer1() const {
        return answer1;
    }

    std::string getAnswer2() const {
        return answer2;
    }

    std::string getAnswer3() const {
        return answer3;
    }

    std::string getAnswer4() const {
        return answer4;
    }

    int getCorrectAnswer() const {
        return correctAnswer;
    }
};

int main() {
    // Create an array of 10 Question objects with trivia questions and answers
    Question triviaQuestions[10] = {
        {"What is the capital of France?", "Berlin", "Paris", "Madrid", "London", 2},
        {"Which planet is known as the Red Planet?", "Mars", "Venus", "Jupiter", "Saturn", 1},
        {"Who wrote 'Romeo and Juliet'?", "Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain", 2},
        {"In what year did World War II end?", "1945", "1939", "1950", "1940", 1},
        {"What is the largest mammal on Earth?", "Elephant", "Blue Whale", "Giraffe", "Polar Bear", 2},
        {"Which programming language is often used for web development?", "Java", "Python", "C++", "JavaScript", 4},
        {"Who painted the Mona Lisa?", "Vincent van Gogh", "Pablo Picasso", "Leonardo da Vinci", "Claude Monet", 3},
        {"What is the capital of Japan?", "Seoul", "Beijing", "Tokyo", "Bangkok", 3},
        {"Which element has the chemical symbol 'O'?", "Oxygen", "Gold", "Iron", "Carbon", 1},
        {"What is the largest ocean on Earth?", "Atlantic Ocean", "Indian Ocean", "Southern Ocean", "Pacific Ocean", 4}
    };

    // Players' scores
    int player1Score = 0;
    int player2Score = 0;

    // Loop through each question
    for (int i = 0; i < 10; ++i) {
        std::cout << "\nQuestion " << (i + 1) << ": " << triviaQuestions[i].getQuestionText() << std::endl;
        std::cout << "1. " << triviaQuestions[i].getAnswer1() << std::endl;
        std::cout << "2. " << triviaQuestions[i].getAnswer2() << std::endl;
        std::cout << "3. " << triviaQuestions[i].getAnswer3() << std::endl;
        std::cout << "4. " << triviaQuestions[i].getAnswer4() << std::endl;

        // Get player 1's answer
        int player1Answer;
        std::cout << "Player 1, enter your answer (1-4): ";
        std::cin >> player1Answer;

        // Validate player 1's answer
        if (player1Answer >= 1 && player1Answer <= 4) {
            // Check if the answer is correct
            if (player1Answer == triviaQuestions[i].getCorrectAnswer()) {
                std::cout << "Correct! Player 1 earns a point." << std::endl;
                player1Score++;
            } else {
                std::cout << "Incorrect! The correct answer is " << triviaQuestions[i].getCorrectAnswer() << "." << std::endl;
            }
        } else {
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
        }

        // Get player 2's answer
        int player2Answer;
        std::cout << "Player 2, enter your answer (1-4): ";
        std::cin >> player2Answer;

        // Validate player 2's answer
        if (player2Answer >= 1 && player2Answer <= 4) {
            // Check if the answer is correct
            if (player2Answer == triviaQuestions[i].getCorrectAnswer()) {
                std::cout << "Correct! Player 2 earns a point." << std::endl;
                player2Score++;
            } else {
                std::cout << "Incorrect! The correct answer is " << triviaQuestions[i].getCorrectAnswer() << "." << std::endl;
            }
        } else {
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
        }
    }

    // Display players' scores
    std::cout << "\nPlayer 1 Score: " << player1Score << std::endl;
    std::cout << "Player 2 Score: " << player2Score << std::endl;

    // Determine the winner
    if (player1Score > player2Score) {
        std::cout << "Player 1 is the winner!" << std::endl;
    } else if (player2Score > player1Score) {
        std::cout << "Player 2 is the winner!" << std::endl;
    } else {
        std::cout << "It's a tie! Both players have the same score." << std::endl;
    }

    return 0;
}
