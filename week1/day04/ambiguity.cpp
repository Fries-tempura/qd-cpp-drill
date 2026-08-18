#include <iostream>

// 情境:两个 print 函数
void print(int x) {
    std::cout << "print(int): " << x << std::endl;
}

void print(int x, int y = 0) {         // 第二个参数有默认值
    std::cout << "print(int, int): " << x << ", " << y << std::endl;
}

int main() {
    //print(5);      // ❌ 编译器懵了:
                   //    print(int) 匹配? 匹配
                   //    print(int, int) 用默认值也匹配? 也匹配
                   //    → 两个都合法 → 二义性 → 报错
    return 0;
}
