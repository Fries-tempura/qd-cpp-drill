#include <iostream>
#include <string>

// 一个通用的"最大值"函数模板
template<typename T>
T myMax(T a, T b) {
    return (a > b) ? a : b;
}

// 一个通用的 Box 类模板
template<typename T>
class Box {
public:
    Box(T value) : value_(value) {}
    T get() const { return value_; }
    void set(T v) { value_ = v; }
private:
    T value_;
};

int main() {
    // 函数模板:同一个 myMax,不同类型
    std::cout << "myMax(3, 7)         = " << myMax(3, 7) << std::endl;
    std::cout << "myMax(1.5, 2.7)     = " << myMax(1.5, 2.7) << std::endl;
    std::cout << "myMax<string>(a, b) = "
              << myMax<std::string>("apple", "banana") << std::endl;

    // 类模板:同一个 Box,不同类型
    Box<int>         b1(42);
    Box<std::string> b2("hello");
    Box<double>      b3(3.14);

    std::cout << "b1.get() = " << b1.get() << std::endl;
    std::cout << "b2.get() = " << b2.get() << std::endl;
    std::cout << "b3.get() = " << b3.get() << std::endl;

    // 类型不匹配 → 编译错误
    // b1.set("wrong");   // ❌ 试着解开这行,看编译报什么错

    return 0;
}
