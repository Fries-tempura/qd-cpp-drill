#include <iostream>

// 一个故意会崩溃的函数
void bad_function() {
    int* p = nullptr;    // p 是一个空指针，指向"什么都没有"
    *p = 42;             // 崩溃点：往空地址写数据 → 段错误
}

int main() {
    std::cout << "About to call bad_function..." << std::endl;
    bad_function();
    std::cout << "This line will never print." << std::endl;
    return 0;
}
