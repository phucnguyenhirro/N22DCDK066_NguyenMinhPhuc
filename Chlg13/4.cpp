#include <iostream>
#include <string>

class PersonalData {
private:
    std::string name;
    std::string address;
    int age;
    std::string phoneNumber;

public:
    // Constructors
    PersonalData() : age(0) {}

    PersonalData(std::string n, std::string addr, int a, std::string phone)
        : name(n), address(addr), age(a), phoneNumber(phone) {}

    // Accessor functions
    std::string getName() const {
        return name;
    }

    std::string getAddress() const {
        return address;
    }

    int getAge() const {
        return age;
    }

    std::string getPhoneNumber() const {
        return phoneNumber;
    }

    // Mutator functions
    void setName(std::string n) {
        name = n;
    }

    void setAddress(std::string addr) {
        address = addr;
    }

    void setAge(int a) {
        age = a;
    }

    void setPhoneNumber(std::string phone) {
        phoneNumber = phone;
    }
};

int main() {
    // Create an instance holding your information
    PersonalData myInfo("Your Name", "Your Address", 25, "123-456-7890");

    // Create instances holding your friends' or family members' information
    PersonalData friend1("Friend1 Name", "Friend1 Address", 30, "111-222-3333");
    PersonalData friend2("Friend2 Name", "Friend2 Address", 35, "444-555-6666");

    // Display information
    std::cout << "Your Information:\n";
    std::cout << "Name: " << myInfo.getName() << "\n";
    std::cout << "Address: " << myInfo.getAddress() << "\n";
    std::cout << "Age: " << myInfo.getAge() << "\n";
    std::cout << "Phone Number: " << myInfo.getPhoneNumber() << "\n\n";

    std::cout << "Friend 1's Information:\n";
    std::cout << "Name: " << friend1.getName() << "\n";
    std::cout << "Address: " << friend1.getAddress() << "\n";
    std::cout << "Age: " << friend1.getAge() << "\n";
    std::cout << "Phone Number: " << friend1.getPhoneNumber() << "\n\n";

    std::cout << "Friend 2's Information:\n";
    std::cout << "Name: " << friend2.getName() << "\n";
    std::cout << "Address: " << friend2.getAddress() << "\n";
    std::cout << "Age: " << friend2.getAge() << "\n";
    std::cout << "Phone Number: " << friend2.getPhoneNumber() << "\n";

    return 0;
}

