#include <iostream>
#include <string>

class Car {
private:
    int yearModel;
    std::string make;
    int speed;

public:
    // Constructor
    Car(int model, std::string carMake) : yearModel(model), make(carMake), speed(0) {}

    // Accessor functions
    int getYearModel() const {
        return yearModel;
    }

    std::string getMake() const {
        return make;
    }

    int getSpeed() const {
        return speed;
    }

    // Member function to accelerate
    void accelerate() {
        speed += 5;
    }

    // Member function to brake
    void brake() {
        speed -= 5;
        if (speed < 0) {
            speed = 0;
        }
    }
};

int main() {
    // Create a Car object
    Car myCar(2022, "Toyota");

    // Accelerate the car five times and display the speed
    std::cout << "Accelerating...\n";
    for (int i = 0; i < 5; ++i) {
        myCar.accelerate();
        std::cout << "Current Speed: " << myCar.getSpeed() << " mph\n";
    }

    // Brake the car five times and display the speed
    std::cout << "\nBraking...\n";
    for (int i = 0; i < 5; ++i) {
        myCar.brake();
        std::cout << "Current Speed: " << myCar.getSpeed() << " mph\n";
    }

    return 0;
}

