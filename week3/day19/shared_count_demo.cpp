#include <iostream>
#include <memory>

struct Widget {
    int id;
    Widget(int i) : id(i) { std::cout << "  Widget(" << id << ") 构造\n"; }
    ~Widget()             { std::cout << "  Widget(" << id << ") 析构\n"; }
};

int main() {
    std::cout << "=== 阶段 1:创建 p1 ===\n";
    auto p1 = std::make_shared<Widget>(1);
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;

    std::cout << "\n=== 阶段 2:p2 = p1(拷贝构造)===\n";
    auto p2 = p1;
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;
    std::cout << "p2.use_count() = " << p2.use_count() << std::endl;

    std::cout << "\n=== 阶段 3:进入内部作用域 ===\n";
    {
        auto p3 = p1;
        std::cout << "内部作用域 count = " << p1.use_count() << std::endl;
    }
    std::cout << "出作用域后 count = " << p1.use_count() << std::endl;

    std::cout << "\n=== 阶段 4:p2 = nullptr(拷贝赋值,减少 p2 的份额)===\n";
    p2.reset();
    std::cout << "p1.use_count() = " << p1.use_count() << std::endl;

    std::cout << "\n=== 阶段 5:std::move 转移 ===\n";
    auto p4 = std::move(p1);
    std::cout << "p1.use_count() = " << p1.use_count() << " (应该是 0)\n";
    std::cout << "p4.use_count() = " << p4.use_count() << " (应该还是 1)\n";

    std::cout << "\n=== 阶段 6:main 结束 ===\n";
    return 0;
}
