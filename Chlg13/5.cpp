#include <iostream>
#include <string>

class RetailItem {
private:
    std::string description;
    int unitsOnHand;
    double price;

public:
    // Constructor
    RetailItem(std::string desc, int units, double itemPrice)
        : description(desc), unitsOnHand(units), price(itemPrice) {}

    // Accessor functions
    std::string getDescription() const {
        return description;
    }

    int getUnitsOnHand() const {
        return unitsOnHand;
    }

    double getPrice() const {
        return price;
    }

    // Mutator functions
    void setDescription(std::string desc) {
        description = desc;
    }

    void setUnitsOnHand(int units) {
        unitsOnHand = units;
    }

    void setPrice(double itemPrice) {
        price = itemPrice;
    }
};

int main() {
    // Create three RetailItem objects
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    // Display information for each item
    std::cout << "Item #1:\n";
    std::cout << "Description: " << item1.getDescription() << "\n";
    std::cout << "Units on Hand: " << item1.getUnitsOnHand() << "\n";
    std::cout << "Price: $" << item1.getPrice() << "\n\n";

    std::cout << "Item #2:\n";
    std::cout << "Description: " << item2.getDescription() << "\n";
    std::cout << "Units on Hand: " << item2.getUnitsOnHand() << "\n";
    std::cout << "Price: $" << item2.getPrice() << "\n\n";

    std::cout << "Item #3:\n";
    std::cout << "Description: " << item3.getDescription() << "\n";
    std::cout << "Units on Hand: " << item3.getUnitsOnHand() << "\n";
    std::cout << "Price: $" << item3.getPrice() << "\n";

    return 0;
}
