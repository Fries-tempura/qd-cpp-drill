#include <iostream>
#include <memory>

class Widget {
public:
    Widget()  { std::cout << "  Widget 构造" << std::endl; }
    ~Widget() { std::cout << "  Widget 析构" << std::endl; }
    void hello() { std::cout << "  Hello!" << std::endl; }
};

int main() {
    std::cout << "=== 阶段 1:创建 p1 ===" << std::endl;
    auto p1 = std::make_shared<Widget>();
    std::cout << "计数: " << p1.use_count() << std::endl;    // 1

    std::cout << "\n=== 阶段 2:p2 = p1(拷贝) ===" << std::endl;
    auto p2 = p1;
    std::cout << "计数: " << p1.use_count() << std::endl;    // 2

    std::cout << "\n=== 阶段 3:{ 内部作用域 p3 = p1 } ===" << std::endl;
    {
        auto p3 = p1;
        std::cout << "计数: " << p1.use_count() << std::endl;   // 3
    }   // ← p3 析构 → 计数 -1
    std::cout << "内部作用域结束后计数: " << p1.use_count() << std::endl;   // 2

    std::cout << "\n=== 阶段 4:main 结束前 ===" << std::endl;
    std::cout << "计数: " << p1.use_count() << std::endl;    // 2

    // 出 main 时:p2 析构 → 1;p1 析构 → 0 → Widget 真正被 delete
    return 0;
}
