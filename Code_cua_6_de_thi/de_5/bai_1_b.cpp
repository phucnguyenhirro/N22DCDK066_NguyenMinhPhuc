#include <iostream>

class A {
    // Định nghĩa lớp A (nếu chưa có)
};

void init(A *&a) {
    A *b = new A();
    a = b;
}

int main() {
    A *obj = nullptr; // Khởi tạo con trỏ để tránh lỗi undefined behavior
    init(obj);

    // Gọi các thao tác cần thiết trên obj...

    delete obj; // Giải phóng bộ nhớ khi không còn sử dụng obj
    obj = nullptr; // Đặt con trỏ về nullptr để tránh sử dụng sau khi đã giải phóng

    return 0;
}
