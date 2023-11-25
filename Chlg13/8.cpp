#include <iostream>

class Circle {
private:
    double radius;
    const double pi = 3.14159;

public:
    // Default Constructor
    Circle() : radius(0.0) {}

    // Constructor with parameter
    Circle(double r) : radius(r) {}

    // Mutator function for radius
    void setRadius(double r) {
        radius = r;
    }

    // Accessor function for radius
    double getRadius() const {
        return radius;
    }

    // Function to calculate and return the area of the circle
    double getArea() const {
        return pi * radius * radius;
    }

    // Function to calculate and return the diameter of the circle
    double getDiameter() const {
        return radius * 2;
    }

    // Function to calculate and return the circumference of the circle
    double getCircumference() const {
        return 2 * pi * radius;
    }
};

int main() {
    // Get the radius from the user
    double radius;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    // Create an instance of the Circle class
    Circle circle(radius);

    // Display the circle's properties
    std::cout << "Area of the circle: " << circle.getArea() << std::endl;
    std::cout << "Diameter of the circle: " << circle.getDiameter() << std::endl;
    std::cout << "Circumference of the circle: " << circle.getCircumference() << std::endl;

    return 0;
}
