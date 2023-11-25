#include <iostream>
#include <string>

// Define the MovieData structure
struct MovieData {
    std::string title;
    std::string director;
    int yearReleased;
    int runningTime; // in minutes
    double productionCost;
    double firstYearRevenue;
};

// Function to display information about a movie, including first year's profit or loss
void displayMovieInfo(const MovieData& movie) {
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Director: " << movie.director << std::endl;
    std::cout << "Year Released: " << movie.yearReleased << std::endl;
    std::cout << "Running Time: " << movie.runningTime << " minutes" << std::endl;
    std::cout << "Production Cost: $" << movie.productionCost << std::endl;
    std::cout << "First Year Revenue: $" << movie.firstYearRevenue << std::endl;

    // Calculate and display first year's profit or loss
    double profitOrLoss = movie.firstYearRevenue - movie.productionCost;
    std::cout << "First Year's Profit/Loss: $" << profitOrLoss << std::endl;
    std::cout << "-------------------------\n";
}

int main() {
    // Create two MovieData variables and initialize their values
    MovieData movie1 = {"Inception", "Christopher Nolan", 2010, 148, 160000000, 825532764};
    MovieData movie2 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142, 25000000, 58700000};

    // Display information about each movie
    std::cout << "Movie 1 Information:\n";
    displayMovieInfo(movie1);

    std::cout << "Movie 2 Information:\n";
    displayMovieInfo(movie2);

    return 0;
}
