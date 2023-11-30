#include <iostream>
#include <cstring>

class BigInteger {
private:
    char* value;

public:
    // Hàm tạo mặc định
    BigInteger() : value(nullptr) {}

    // Hàm tạo từ chuỗi
    BigInteger(const char* str) {
        value = new char[strlen(str) + 1];
        strcpy(value, str);
    }

    // Hàm hủy
    ~BigInteger() {
        delete[] value;
    }

    // Toán tử so sánh bằng
    bool operator==(const BigInteger& other) const {
        return strcmp(value, other.value) == 0;
    }

    // Toán tử nhập từ người dùng
    friend std::istream& operator>>(std::istream& is, BigInteger& obj) {
        char buffer[200]; // Giả sử chuỗi có độ dài tối đa là 200
        is >> buffer;

        delete[] obj.value; // Đảm bảo giải phóng bộ nhớ cũ trước khi cấp phát mới

        obj.value = new char[strlen(buffer) + 1];
        strcpy(obj.value, buffer);

        return is;
    }

    // Toán tử xuất ra màn hình
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& obj) {
        os << obj.value;
        return os;
    }
};

int main() {
    // Sử dụng lớp BigInteger
    BigInteger num1("12345");
    std::cout << "num1: " << num1 << std::endl;

    BigInteger num2;
    std::cout << "Enter a BigInteger: ";
    std::cin >> num2;
    std::cout << "You entered: " << num2 << std::endl;

    return 0;
}
