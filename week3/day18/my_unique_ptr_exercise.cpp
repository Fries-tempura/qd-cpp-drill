#include <iostream>
#include <utility>  // std::move

template<typename T>
class MyUniquePtr {
public:
    // TODO 1: 构造函数,接管原始指针 p(默认 nullptr)
    explicit MyUniquePtr(T* p = nullptr) : ptr_(p) {}

    // TODO 2: 析构函数,delete ptr_
    ~MyUniquePtr() {
        delete ptr_;
    }

    // TODO 3: 禁用拷贝构造和拷贝赋值
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // TODO 4: 移动构造:偷 other 的指针,把 other 清空
    MyUniquePtr(MyUniquePtr&& other) noexcept : ptr_(other.ptr_) {
        other.ptr_ = nullptr;
    }

    // TODO 5: 移动赋值:先释放自己的,再偷 other 的
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    // TODO 6: 重载 * 和 ->
    T& operator*()  const { return *ptr_; }
    T* operator->() const { return ptr_; }

    // TODO 7: get() 返回原始指针
    T* get() const { return ptr_; }

private:
    T* ptr_;
};

// -------------------- 测试代码(不要改) --------------------
struct Widget {
    int id;
    Widget(int i) : id(i) { std::cout << "  Widget(" << id << ") 构造\n"; }
    ~Widget()             { std::cout << "  Widget(" << id << ") 析构\n"; }
    void hi() { std::cout << "  hi from Widget(" << id << ")\n"; }
};

int main() {
    std::cout << "=== 阶段 1:创建 p1 ===\n";
    MyUniquePtr<Widget> p1(new Widget(1));
    p1->hi();
    (*p1).hi();
    std::cout << "p1.get() = " << p1.get() << " (非 0)\n";

    std::cout << "\n=== 阶段 2:p2 = std::move(p1)(移动构造)===\n";
    MyUniquePtr<Widget> p2 = std::move(p1);
    std::cout << "p1.get() = " << p1.get() << " (应该是 0)\n";
    std::cout << "p2.get() = " << p2.get() << " (应该非 0)\n";
    p2->hi();

    std::cout << "\n=== 阶段 3:测试移动赋值 ===\n";
    MyUniquePtr<Widget> p3(new Widget(3));
    std::cout << "赋值前:\n";
    p3 = std::move(p2);   // p3 原来的 Widget(3) 应该被析构
    std::cout << "赋值后:\n";
    std::cout << "p2.get() = " << p2.get() << " (应该是 0)\n";
    std::cout << "p3.get() = " << p3.get() << " (应该非 0,指向 Widget(1))\n";
    p3->hi();

    std::cout << "\n=== 阶段 4:main 结束(观察析构)===\n";
    // 应该只看到一次 Widget(1) 析构
    return 0;
}

// -------------------- 附加题:编译时验证禁用拷贝 --------------------
// 完成 TODO 3 后,把下面这段解开注释,编译应该失败:
//
// void test_copy_disabled() {
//     MyUniquePtr<Widget> a(new Widget(99));
//     MyUniquePtr<Widget> b = a;   // ❌ 编译错误:拷贝被禁用
// }
