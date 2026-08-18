#include <iostream>
#include <string>

class Shape {
public:
    Shape(const std::string& name) : name_(name) {}
    void describe() const {
        std::cout << "我是形状[" << name_ << "]" << std::endl;
    }

    // ★ 注意:没有 virtual!
    double area() const { return 0; }

protected:
    std::string name_;
};

class Circle : public Shape {
public:
    Circle(const std::string& name, double radius)
        : Shape(name), radius_(radius) {}

    double area() const {           // 想"覆盖"父类的 area
        return 3.14 * radius_ * radius_;
    }
private:
    double radius_;
};

// 一个通用函数,接受任何 Shape
void printShapeArea(const Shape& s) {
    std::cout << "printShapeArea 里调用 area(): " << s.area() << std::endl;
}

int main() {
    Circle c("圆1", 5.0);

    // 直接调 Circle 的方法 → 调用 Circle::area() ✅
    std::cout << "直接调 c.area(): " << c.area() << std::endl;

    // 通过 Shape 引用调 → 想调 Circle::area(),但实际...?
    printShapeArea(c);

    return 0;
}
