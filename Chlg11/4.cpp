#include <iostream>
#include <iomanip>
#include <string>

// Define the structure for weather data
struct WeatherData {
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
};

// Function to get weather data from the user for a specific month
void getWeatherData(WeatherData& month) {
    do {
        std::cout << "Enter total rainfall for the month: ";
        std::cin >> month.totalRainfall;

        std::cout << "Enter high temperature for the month: ";
        std::cin >> month.highTemperature;

        std::cout << "Enter low temperature for the month: ";
        std::cin >> month.lowTemperature;

        // Calculate average temperature
        month.averageTemperature = (month.highTemperature + month.lowTemperature) / 2.0;

        // Input validation: Check for temperatures within the specified range
        if (month.highTemperature < -100 || month.highTemperature > 140 ||
            month.lowTemperature < -100 || month.lowTemperature > 140) {
            std::cout << "Temperature values must be within the range between -100 and +140 degrees Fahrenheit.\n";
        }
    } while (month.highTemperature < -100 || month.highTemperature > 140 ||
             month.lowTemperature < -100 || month.lowTemperature > 140);
}

int main() {
    const int numMonths = 12;
    WeatherData yearlyData[numMonths];

    // Get weather data for each month
    for (int i = 0; i < numMonths; ++i) {
        std::cout << "\nEnter weather data for Month " << i + 1 << ":\n";
        getWeatherData(yearlyData[i]);
    }

    // Calculate and display statistics for the entire year
    double totalRainfall = 0;
    double totalAverageTemperature = 0;
    double highestTemperature = yearlyData[0].highTemperature;
    double lowestTemperature = yearlyData[0].lowTemperature;
    int highestMonth = 1;
    int lowestMonth = 1;

    for (int i = 0; i < numMonths; ++i) {
        totalRainfall += yearlyData[i].totalRainfall;
        totalAverageTemperature += yearlyData[i].averageTemperature;

        // Check for highest temperature
        if (yearlyData[i].highTemperature > highestTemperature) {
            highestTemperature = yearlyData[i].highTemperature;
            highestMonth = i + 1;
        }

        // Check for lowest temperature
        if (yearlyData[i].lowTemperature < lowestTemperature) {
            lowestTemperature = yearlyData[i].lowTemperature;
            lowestMonth = i + 1;
        }
    }

    double averageMonthlyTemperature = totalAverageTemperature / numMonths;

    // Display statistics for the entire year
    std::cout << "\nYearly Statistics:\n";
    std::cout << "Average Monthly Rainfall: " << totalRainfall / numMonths << " inches\n";
    std::cout << "Total Rainfall for the Year: " << totalRainfall << " inches\n";
    std::cout << "Highest Temperature for the Year: " << highestTemperature << " (Month " << highestMonth << ")\n";
    std::cout << "Lowest Temperature for the Year: " << lowestTemperature << " (Month " << lowestMonth << ")\n";
    std::cout << "Average of All Monthly Average Temperatures: " << averageMonthlyTemperature << " degrees Fahrenheit\n";

    return 0;
}
