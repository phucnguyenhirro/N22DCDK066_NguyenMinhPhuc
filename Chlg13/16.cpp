#include <iostream>

class TemperatureChecker {
private:
    double temperature;

public:
    // Constructor
    TemperatureChecker(double temp) : temperature(temp) {}

    // Accessor and mutator functions for temperature
    double getTemperature() const {
        return temperature;
    }

    void setTemperature(double temp) {
        temperature = temp;
    }

    // Functions to check freezing and boiling points
    bool isEthylFreezing() const {
        return temperature <= -173;
    }

    bool isEthylBoiling() const {
        return temperature >= 172;
    }

    bool isOxygenFreezing() const {
        return temperature <= -362;
    }

    bool isOxygenBoiling() const {
        return temperature >= -306;
    }

    bool isWaterFreezing() const {
        return temperature <= 32;
    }

    bool isWaterBoiling() const {
        return temperature >= 212;
    }
};

int main() {
    // Get temperature from the user
    double userTemperature;
    std::cout << "Enter a temperature: ";
    std::cin >> userTemperature;

    // Create an instance of the TemperatureChecker class
    TemperatureChecker temperatureChecker(userTemperature);

    // Display substances that will freeze or boil at the given temperature
    std::cout << "\nSubstances affected at " << userTemperature << " degrees:\n";

    if (temperatureChecker.isEthylFreezing()) {
        std::cout << "Ethyl Alcohol will freeze.\n";
    }
    if (temperatureChecker.isEthylBoiling()) {
        std::cout << "Ethyl Alcohol will boil.\n";
    }

    if (temperatureChecker.isOxygenFreezing()) {
        std::cout << "Oxygen will freeze.\n";
    }
    if (temperatureChecker.isOxygenBoiling()) {
        std::cout << "Oxygen will boil.\n";
    }

    if (temperatureChecker.isWaterFreezing()) {
        std::cout << "Water will freeze.\n";
    }
    if (temperatureChecker.isWaterBoiling()) {
        std::cout << "Water will boil.\n";
    }

    return 0;
}
