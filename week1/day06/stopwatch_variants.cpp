#include <iostream>

// ========== 版本 1:成员是 int(最简单) ==========
class CounterSW {
public:
    CounterSW() : count_(0) {
        std::cout << "CounterSW created" << std::endl;
    }
    ~CounterSW() {
        std::cout << "CounterSW destroyed, count = " << count_ << std::endl;
    }
    void tick() { count_++; }

private:
    int count_;              // ← 类型是 int
};

// ========== 版本 2:成员是 double ==========
class DoubleSW {
public:
    DoubleSW() : value_(3.14) {
        std::cout << "DoubleSW created" << std::endl;
    }
    ~DoubleSW() {
        std::cout << "DoubleSW destroyed, value = " << value_ << std::endl;
    }

private:
    double value_;           // ← 类型是 double
};

// ========== 版本 3:成员是 string ==========
class StringSW {
public:
    StringSW() : name_("hello") {
        std::cout << "StringSW created" << std::endl;
    }
    ~StringSW() {
        std::cout << "StringSW destroyed, name = " << name_ << std::endl;
    }

private:
    std::string name_;       // ← 类型是 string
};

int main() {
    CounterSW c;
    c.tick();
    c.tick();

    DoubleSW d;

    StringSW s;

    return 0;
    // 三个对象都会自动析构
}
