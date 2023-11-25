#include <iostream>

class Population {
private:
    double population;
    double births;
    double deaths;

public:
    // Constructor
    Population(double pop, double b, double d) : population(pop), births(b), deaths(d) {}

    // Function to calculate and return the birth rate
    double calculateBirthRate() const {
        return births / population;
    }

    // Function to calculate and return the death rate
    double calculateDeathRate() const {
        return deaths / population;
    }
};

int main() {
    // Example data













    
    double population = 100000;
    double births = 8000;
    double deaths = 6000;

    // Create an instance of the Population class
    Population populationData(population, births, deaths);

    // Display the birth rate and death rate
    std::cout << "Birth Rate: " << populationData.calculateBirthRate() << std::endl;
    std::cout << "Death Rate: " << populationData.calculateDeathRate() << std::endl;

    return 0;
}
