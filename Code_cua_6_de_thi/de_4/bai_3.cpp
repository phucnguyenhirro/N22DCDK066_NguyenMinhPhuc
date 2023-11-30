#include <iostream>
#include <string>

class Contract {
protected:
    std::string contractType;
    double callRate;
    double dataRate;
    double freeDataThreshold;
    double subscriptionFee;

public:
    Contract(std::string type, double call, double data, double freeData, double fee)
        : contractType(type), callRate(call), dataRate(data), freeDataThreshold(freeData), subscriptionFee(fee) {}

    virtual double calculateCallFee(double minutes) {
        return minutes * callRate;
    }

    virtual double calculateDataFee(double dataUsage) {
        return dataUsage * dataRate;
    }

    virtual double calculateOverageFee(double overageData) {
        return calculateDataFee(overageData);
    }

    virtual double calculateTotalFee(double callDuration, double dataUsage) {
        double callFee = calculateCallFee(callDuration);
        double dataFee = (dataUsage <= freeDataThreshold) ? 0 : calculateOverageFee(dataUsage - freeDataThreshold);
        return callFee + dataFee + 0.1 * (callFee + dataFee);
    }

    virtual ~Contract() {}
};

class BasicContract : public Contract {
public:
    BasicContract(double call, double data) : Contract("Basic", call, data, 0, 0) {}
};

class DataFreeContract : public Contract {
public:
    DataFreeContract(double call, double data, double freeData) : Contract("DataFree", call, data, freeData, 0) {}
};

class DataFixContract : public Contract {
public:
    DataFixContract(double call, double data, double discount, double fixedFee)
        : Contract("DataFix", call, data, 0, fixedFee - (discount / 100) * (call * callRate + data * dataRate)) {}
};

class Customer {
private:
    std::string fullName;
    std::string idCard;
    std::string address;
    Contract* contract;

public:
    Customer(std::string name, std::string id, std::string addr, Contract* c)
        : fullName(name), idCard(id), address(addr), contract(c) {}

    void displayContractDetails() {
        std::cout << "Customer: " << fullName << std::endl;
        std::cout << "Contract Type: " << contract->contractType << std::endl;
        std::cout << "Call Rate: " << contract->callRate << std::endl;
        std::cout << "Data Rate: " << contract->dataRate << std::endl;
        std::cout << "Free Data Threshold: " << contract->freeDataThreshold << std::endl;
        std::cout << "Subscription Fee: " << contract->subscriptionFee << std::endl;
    }

    double calculateMonthlyFee(double callDuration, double dataUsage) {
        return contract->calculateTotalFee(callDuration, dataUsage);
    }

    ~Customer() {
        delete contract;
    }
};

int main() {
    BasicContract basicContract(1000, 200);
    DataFreeContract dataFreeContract(1000, 200, 500);

    Customer customer1("John Doe", "123456789", "123 Main St", &basicContract);
    Customer customer2("Jane Doe", "987654321", "456 Oak St", &dataFreeContract);

    customer1.displayContractDetails();
    std::cout << "Monthly Fee: " << customer1.calculateMonthlyFee(120, 3000) << std::endl;

    std::cout << "\n";

    customer2.displayContractDetails();
    std::cout << "Monthly Fee: " << customer2.calculateMonthlyFee(150, 600) << std::endl;

    return 0;
}
