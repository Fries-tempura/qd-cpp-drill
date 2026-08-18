#include <iostream>

// ============================================================
// 版本 1：值传递（错误示范：根本没交换外面的值）
// ============================================================
void swap_by_value(int a, int b) {
    std::cout << "  [swap_by_value 内部] 交换前: a=" << a << ", b=" << b << std::endl;
    int tmp = a;
    a = b;
    b = tmp;
    std::cout << "  [swap_by_value 内部] 交换后: a=" << a << ", b=" << b << std::endl;
}

// ============================================================
// 版本 2：指针传递（能交换，但语法麻烦，还要防 nullptr）
// ============================================================
void swap_by_pointer(int* a, int* b) {
    if (a == nullptr || b == nullptr) {
        std::cout << "  [swap_by_pointer] 有 nullptr,不能交换" << std::endl;
        return;
    }
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// ============================================================
// 版本 3：引用传递（推荐:能交换,语法干净,不用防 null）
// ============================================================
void swap_by_reference(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    // ---- 测试版本 1：值传递 ----
    std::cout << "=== 版本 1: 值传递 ===" << std::endl;
    int x1 = 1, y1 = 2;
    std::cout << "调用前: x1=" << x1 << ", y1=" << y1 << std::endl;
    swap_by_value(x1, y1);
    std::cout << "调用后: x1=" << x1 << ", y1=" << y1 << " (没变!)" << std::endl;

    // ---- 测试版本 2：指针传递 ----
    std::cout << "\n=== 版本 2: 指针传递 ===" << std::endl;
    int x2 = 1, y2 = 2;
    std::cout << "调用前: x2=" << x2 << ", y2=" << y2 << std::endl;
    swap_by_pointer(&x2, &y2);
    std::cout << "调用后: x2=" << x2 << ", y2=" << y2 << " (真交换了)" << std::endl;

    // ---- 测试版本 3：引用传递 ----
    std::cout << "\n=== 版本 3: 引用传递 ===" << std::endl;
    int x3 = 1, y3 = 2;
    std::cout << "调用前: x3=" << x3 << ", y3=" << y3 << std::endl;
    swap_by_reference(x3, y3);
    std::cout << "调用后: x3=" << x3 << ", y3=" << y3 << " (也真交换了,而且语法最干净)" << std::endl;

    return 0;
}
