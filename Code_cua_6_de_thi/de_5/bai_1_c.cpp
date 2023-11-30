#include <iostream>

class Singleton {
private:
    // Biến tĩnh để lưu trữ thể hiện duy nhất
    static Singleton* instance;

    // Hàm tạo và hủy được ẩn đi để ngăn chặn việc tạo thêm thể hiện từ bên ngoài
    Singleton() {}
    ~Singleton() {}

public:
    // Phương thức tĩnh để trả về thể hiện duy nhất
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Các phương thức khác của lớp

    // Khởi tạo biến tĩnh
    static Singleton* instance;
};

// Khởi tạo biến tĩnh
Singleton* Singleton::instance = nullptr;

int main() {
    // Sử dụng lớp Singleton
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();

    // Kiểm tra xem obj1 và obj2 có cùng một thể hiện hay không
    if (obj1 == obj2) {
        std::cout << "obj1 and obj2 share the same instance." << std::endl;
    } else {
        std::cout << "obj1 and obj2 do not share the same instance." << std::endl;
    }

    return 0;
}

