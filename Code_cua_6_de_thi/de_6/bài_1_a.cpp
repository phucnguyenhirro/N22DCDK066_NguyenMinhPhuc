#include <iostream>

// Base class Shape
class Shape {
public:
    virtual double calculateArea() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Shape() {
        std::cout << "destruct Shape" << std::endl;
    }
};

// Derived class Ellipse
class Ellipse : public Shape {
private:
    double a;
    double b;

public:
    Ellipse(double a, double b) : a(a), b(b) {}

    double calculateArea() const override {
        return 3.14159 * a * b;
    }

    void printInfo() const override {
        std::cout << "Ellipse(a=" << a << ", b=" << b << ")" << std::endl;
        std::cout << calculateArea() << std::endl;
    }

    ~Ellipse() override {
        std::cout << "destruct Ellipse" << std::endl;
    }
};

int main() {
    // Create an Ellipse object
    Ellipse ellipse(0.333333, 3);

    // Print information using the Shape pointer
    Shape* shape = &ellipse;
    shape->printInfo();

    // Destruct Ellipse and Shape
    return 0;
}
