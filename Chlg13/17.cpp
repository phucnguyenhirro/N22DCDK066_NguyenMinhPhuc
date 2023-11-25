#include <iostream>
#include <string>

class InventoryItem {
private:
    std::string itemName;
    double cost;
    int onHand;

public:
    // Constructors
    InventoryItem() : itemName(""), cost(0.0), onHand(0) {}
    InventoryItem(std::string name, double itemCost, int quantity) : itemName(name), cost(itemCost), onHand(quantity) {}

    // Accessor functions
    std::string getItemName() const {
        return itemName;
    }

    double getItemCost() const {
        return cost;
    }

    int getOnHand() const {
        return onHand;
    }

    // Mutator function
    void setOnHand(int quantity) {
        onHand = quantity;
    }
};

class CashRegister {
private:
    InventoryItem item;

public:
    // Constructor
    CashRegister(const InventoryItem& inventoryItem) : item(inventoryItem) {}

    // Function to process a purchase
    void processPurchase(int quantity) {
        // Get the item's cost and calculate unit price with 30% profit
        double unitPrice = item.getItemCost() * 1.3;

        // Calculate purchase subtotal
        double subtotal = unitPrice * quantity;

        // Calculate sales tax (6%)
        double tax = subtotal * 0.06;

        // Calculate total
        double total = subtotal + tax;

        // Display purchase details
        std::cout << "Purchase Subtotal: $" << subtotal << std::endl;
        std::cout << "Sales Tax: $" << tax << std::endl;
        std::cout << "Total: $" << total << std::endl;

        // Update onHand quantity
        int updatedQuantity = item.getOnHand() - quantity;
        item.setOnHand(updatedQuantity);
    }
};

int main() {
    // Example usage
    InventoryItem item("Widget", 10.0, 50);
    CashRegister cashRegister(item);

    // Get user input for quantity
    int quantity;
    std::cout << "Enter the quantity to purchase: ";
    std::cin >> quantity;

    // Process the purchase and display results
    cashRegister.processPurchase(quantity);

    // Display updated onHand quantity
    std::cout << "Updated onHand quantity: " << item.getOnHand() << std::endl;

    return 0;
}
