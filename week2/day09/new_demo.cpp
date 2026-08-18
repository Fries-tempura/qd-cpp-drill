#include <iostream>

int main() {
    std::cout << "你想创建多大的数组? ";
    int n;
    std::cin >> n;                   // 运行时才知道 n 是多少

    // 用 new 动态分配一个 n 个 int 的数组
    int* arr = new int[n];

    std::cout << "arr 指向的地址: " << arr << std::endl;
    std::cout << "已分配 " << n << " 个 int 的空间" << std::endl;

    // 填数字
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    // 打印
    std::cout << "内容: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // ★ 用完必须还回去,否则内存泄漏
    delete[] arr;
    std::cout << "已释放" << std::endl;

    return 0;
}
