#include <iostream>

// ================ 极简父类和子类 ================
class Animal {
public:
    virtual void speak() {                    // ← 注意没有 virtual
        std::cout << "我是动物" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {                    // 子类"覆盖"
        std::cout << "汪汪汪" << std::endl;
    }
};

// ================ 一个外部函数 ================
void test(Animal& x) {                // ★ 参数类型是 Animal&
    x.speak();                         // ★ 调用 x 的 speak
}

int main() {
    Dog d;                             // ★ 造一只狗

    std::cout << "--- 测试 1:直接调 d.speak() ---" << std::endl;
    d.speak();                         // 期望:汪汪汪 (调 Dog 的)

    std::cout << "--- 测试 2:通过 test(d) 调 ---" << std::endl;
    test(d);                           // 期望:汪汪汪? 还是 我是动物?

    return 0;
}
