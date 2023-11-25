#include <iostream>
#include <string>

// Define the MovieData structure
struct MovieData {
    std::string title;
    std::string director;
    int yearReleased;
    int runningTime;
    double productionCost;
    double firstYearRevenue;
};

// Function to display information about a movie including profit or loss
void displayMovieInfo(const MovieData& movie) {
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Director: " << movie.director << std::endl;
    std::cout << "Year Released: " << movie.yearReleased << std::endl;
    std::cout << "Running Time: " << movie.runningTime << " minutes" << std::endl;
    std::cout << "Production Cost: $" << movie.productionCost << std::endl;
    std::cout << "First Year Revenue: $" << movie.firstYearRevenue << std::endl;

    // Calculate and display first year's profit or loss
    double profitLoss = movie.firstYearRevenue - movie.productionCost;
    std::cout << "First Year Profit/Loss: $" << profitLoss << std::endl;

    std::cout << "------------------------\n";
}

int main() {
    // Create two MovieData variables and initialize their values
    MovieData movie1 = {"Inception", "Christopher Nolan", 2010, 148, 160000000, 825532764};
    MovieData movie2 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142, 25000000, 28341469};

    // Display information about each movie using the updated function
    displayMovieInfo(movie1);
    displayMovieInfo(movie2);

    return 0;
}
