#include <iostream>

// 假装 Dog 里持有一个"资源"(比如 new 出来的内存)
class Animal {
public:
    Animal() { std::cout << "Animal 构造" << std::endl; }

    // ★ 注意:没有 virtual!
    virtual ~Animal() { std::cout << "Animal 析构" << std::endl; }
};

class Dog : public Animal {
public:
    Dog() {
        std::cout << "Dog 构造" << std::endl;
        resource_ = new int[100];   // ★ 假装借了资源
    }

    ~Dog() {
        std::cout << "Dog 析构 (释放资源)" << std::endl;
        delete[] resource_;          // ★ 必须释放
    }
private:
    int* resource_;
};

int main() {
    std::cout << "=== 用 Animal* 指向 Dog ===" << std::endl;
    Animal* a = new Dog();

    std::cout << "\n=== delete a ===" << std::endl;
    delete a;                        // ★ 会调用谁的析构?

    return 0;
}
