#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // ---- 变体 1:const int* ---- (指向常量的指针)
    const int* p1 = &x;
    std::cout << "p1 指向 x, *p1 = " << *p1 << std::endl;
    // *p1 = 99;  // 试着解注释这一行,看编译器怎么报错
    p1 = &y;     // ✅ 允许:改指
    std::cout << "p1 改指向 y, *p1 = " << *p1 << std::endl;

    // ---- 变体 2:int* const ---- (常量指针)
    int* const p2 = &x;
    std::cout << "\np2 指向 x, *p2 = " << *p2 << std::endl;
    *p2 = 99;    // ✅ 允许:通过 p2 改 x 的值
    std::cout << "*p2 = 99 之后, x = " << x << std::endl;
    // p2 = &y;   // 试着解注释这一行,看编译器怎么报错

    // ---- 变体 3:const int* const ---- (双 const)
    const int* const p3 = &x;
    std::cout << "\np3 指向 x, *p3 = " << *p3 << std::endl;
    // *p3 = 88;   // 试着解注释:报错
    // p3 = &y;    // 试着解注释:报错

    return 0;
}
