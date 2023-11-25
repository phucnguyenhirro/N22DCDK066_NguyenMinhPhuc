#include <iostream>
#include <string>

// Define the MovieData structure
struct MovieData {
    std::string title;
    std::string director;
    int yearReleased;
    int runningTime;
};

// Function to display information about a movie
void displayMovieInfo(const MovieData& movie) {
    std::cout << "Title: " << movie.title << std::endl;
    std::cout << "Director: " << movie.director << std::endl;
    std::cout << "Year Released: " << movie.yearReleased << std::endl;
    std::cout << "Running Time: " << movie.runningTime << " minutes" << std::endl;
    std::cout << "------------------------\n";
}

int main() {
    // Create two MovieData variables and initialize their values
    MovieData movie1 = {"Inception", "Christopher Nolan", 2010, 148};
    MovieData movie2 = {"The Shawshank Redemption", "Frank Darabont", 1994, 142};

    // Display information about each movie using the function
    displayMovieInfo(movie1);
    displayMovieInfo(movie2);

    return 0;
}
