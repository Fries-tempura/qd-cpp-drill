#include <iostream>
#include <memory>          // ★ 智能指针的头文件

// 一个简单的类,便于观察构造/析构
class Widget {
public:
    Widget()  { std::cout << "  Widget 构造" << std::endl; }
    ~Widget() { std::cout << "  Widget 析构" << std::endl; }

    void hello() { std::cout << "  Hello!" << std::endl; }
};

int main() {
    std::cout << "=== 场景 1:裸指针(容易漏 delete) ===" << std::endl;
    {
        Widget* p = new Widget();
        p->hello();
        // ★ 忘记 delete → 析构永远不跑,泄漏
    }
    std::cout << "(注意:没打印'Widget 析构'!内存泄漏)" << std::endl;

    std::cout << "\n=== 场景 2:unique_ptr(自动清理) ===" << std::endl;
    {
        std::unique_ptr<Widget> p(new Widget());
        p->hello();                                 // 用法和裸指针一样
        // ★ 出大括号,p 析构 → 自动 delete 内部的 Widget
    }
    std::cout << "(打印了'Widget 析构' → 自动清理成功)" << std::endl;

    return 0;
}
