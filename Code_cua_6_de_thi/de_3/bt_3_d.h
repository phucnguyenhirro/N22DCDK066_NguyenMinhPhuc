
#include <iostream>

class absList {
public:
    int dataId;
    absList* subLst;

    // Constructor
    absList(int id) : dataId(id), subLst(nullptr) {}

    // Phương thức xuất danh sách
    void showAll(std::ostream& outDev) {
        // Duyệt qua các phần tử của danh sách liên kết
        for (absList* temp = this; temp; temp = temp->subLst) {
            // Xuất giá trị của mỗi phần tử
            outDev << temp->dataId << " ";
        }

        // Xuất dòng mới để kết thúc xuất
        outDev << std::endl;
    }
};

int main() {
    // Tạo một danh sách liên kết đơn giản để kiểm tra
    absList* myList = new absList(1);
    myList->subLst = new absList(2);
    myList->subLst->subLst = new absList(3);

    // Gọi hàm xuất
    myList->showAll(std::cout);

    // Giải phóng bộ nhớ
    delete myList->subLst->subLst;
    delete myList->subLst;
    delete myList;

    return 0;
}

