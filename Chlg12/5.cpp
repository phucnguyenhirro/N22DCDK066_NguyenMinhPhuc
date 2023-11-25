#include <iostream>
#include <string>

const int NUM_MONTHS = 12;

// Enumerated data type for months
enum Month {
    JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE,
    JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

// Define the WeatherData structure
struct WeatherData {
    double totalRainfall;
    double highTemperature;
    double lowTemperature;
    double averageTemperature;
};

// Function to input weather data for a month
void inputWeatherData(WeatherData& month, Month monthEnum) {
    std::cout << "Enter weather data for " << monthEnum + 1 << ":\n";
    std::cout << "Total Rainfall (in inches): ";
    std::cin >> month.totalRainfall;
    std::cout << "High Temperature (in degrees Fahrenheit): ";
    std::cin >> month.highTemperature;
    std::cout << "Low Temperature (in degrees Fahrenheit): ";
    std::cin >> month.lowTemperature;

    // Calculate average temperature
    month.averageTemperature = (month.highTemperature + month.lowTemperature) / 2.0;
}

int main() {
    // Create an array of WeatherData structures for each month
    WeatherData yearlyWeather[NUM_MONTHS];

    // Input weather data for each month using the enumerated type
    for (int i = 0; i < NUM_MONTHS; ++i) {
        inputWeatherData(yearlyWeather[i], static_cast<Month>(i));
    }

    // Calculate and display statistics
    double totalYearlyRainfall = 0.0;
    double highestTemperature = yearlyWeather[JANUARY].highTemperature;
    double lowestTemperature = yearlyWeather[JANUARY].lowTemperature;
    int highestMonth = JANUARY + 1;
    int lowestMonth = JANUARY + 1;

    for (int i = 0; i < NUM_MONTHS; ++i) {
        totalYearlyRainfall += yearlyWeather[i].totalRainfall;

        if (yearlyWeather[i].highTemperature > highestTemperature) {
            highestTemperature = yearlyWeather[i].highTemperature;
            highestMonth = i + 1;
        }

        if (yearlyWeather[i].lowTemperature < lowestTemperature) {
            lowestTemperature = yearlyWeather[i].lowTemperature;
            lowestMonth = i + 1;
        }
    }

    double averageMonthlyTemperature = 0.0;
    for (int i = 0; i < NUM_MONTHS; ++i) {
        averageMonthlyTemperature += yearlyWeather[i].averageTemperature;
    }
    averageMonthlyTemperature /= NUM_MONTHS;

    std::cout << "\nStatistics for the Year:\n";
    std::cout << "Average Monthly Rainfall: " << totalYearlyRainfall / NUM_MONTHS << " inches\n";
    std::cout << "Total Yearly Rainfall: " << totalYearlyRainfall << " inches\n";
    std::cout << "Highest Temperature: " << highestTemperature << " degrees Fahrenheit (Month " << highestMonth << ")\n";
    std::cout << "Lowest Temperature: " << lowestTemperature << " degrees Fahrenheit (Month " << lowestMonth << ")\n";
    std::cout << "Average of Monthly Average Temperatures: " << averageMonthlyTemperature << " degrees Fahrenheit\n";

    return 0;
}
