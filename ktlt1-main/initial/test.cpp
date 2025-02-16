#include <iostream>

bool isEven(int number) {
    return (number % 2 == 0);
}

int main() {
    int num = 10;
    {
        // Khối lệnh độc lập
        if (isEven(num)) {
            std::cout << num << " là số chẵn." << std::endl;
            return 0; // Kết thúc hàm main ngay lập tức
        }
    }
    // Phần này sẽ không được thực thi nếu num là số chẵn
    std::cout << num << " là số lẻ." << std::endl;
    return 0;
}
