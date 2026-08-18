#include <iostream>

int main() {
    int a = 10;
    int& b = a;       // b 是 a 的别名

    std::cout << "初始状态: a = " << a << ", b = " << b << std::endl;
    std::cout << "a 的地址: " << &a << std::endl;
    std::cout << "b 的地址: " << &b << std::endl;
    std::cout << "两个地址是否相同? " << (&a == &b ? "是" : "否") << std::endl;

    std::cout << "\n--- 通过 b 修改 ---" << std::endl;
    b = 20;
    std::cout << "b = 20 之后: a = " << a << ", b = " << b << std::endl;

    std::cout << "\n--- 通过 a 修改 ---" << std::endl;
    a = 30;
    std::cout << "a = 30 之后: a = " << a << ", b = " << b << std::endl;

    return 0;
}
