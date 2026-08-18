#include <iostream>
#include <string>

class Point {
public:
    // 重载构造函数 1:无参
    Point() : x(0), y(0) {
        std::cout << "调用了无参构造" << std::endl;
    }

    // 重载构造函数 2:两个 int
    Point(int x_val, int y_val) : x(x_val), y(y_val) {
        std::cout << "调用了 (int, int) 构造" << std::endl;
    }

    // 重载构造函数 3:一个 int(x 和 y 都填这个值)
    Point(int both) : x(both), y(both) {
        std::cout << "调用了 (int) 构造" << std::endl;
    }

    void print() const {
        std::cout << "  → (" << x << ", " << y << ")" << std::endl;
    }

private:
    int x, y;
};

// 普通函数也能重载
void greet() {
    std::cout << "Hello!" << std::endl;
}

void greet(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

void greet(const std::string& name, int times) {
    for (int i = 0; i < times; ++i) {
        std::cout << "Hello, " << name << "!" << std::endl;
    }
}

int main() {
    std::cout << "=== Point 构造函数重载 ===" << std::endl;
    Point p1;              p1.print();      // 调无参
    Point p2(3, 4);        p2.print();      // 调 (int, int)
    Point p3(7);           p3.print();      // 调 (int)

    std::cout << "\n=== 函数重载 ===" << std::endl;
    greet();
    greet("Alice");
    greet("Bob", 3);

    return 0;
}
