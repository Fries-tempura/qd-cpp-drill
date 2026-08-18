#include <iostream>
#include <string>

class Shape {
public:
    Shape(const std::string& name) : name_(name) {}
    void describe() const {
        std::cout << "我是形状[" << name_ << "]" << std::endl;
    }

    // ★ 加 virtual → 支持多态
    virtual double area() const { return 0; }

protected:
    std::string name_;
};

class Circle : public Shape {
public:
    Circle(const std::string& name, double radius)
        : Shape(name), radius_(radius) {}

    // ★ 用 override 关键字,更清晰(编译器帮你检查是否真的覆盖了)
    double area() const override {
        return 3.14 * radius_ * radius_;
    }
private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(const std::string& name, double w, double h)
        : Shape(name), width_(w), height_(h) {}

    double area() const override {
        return width_ * height_;
    }
private:
    double width_, height_;
};

void printShapeArea(const Shape& s) {
    s.describe();
    std::cout << "面积 = " << s.area() << std::endl;
}

int main() {
    Circle c("圆1", 5.0);
    Rectangle r("矩形1", 3.0, 4.0);

    std::cout << "=== 通过 Shape& 调用 area() ===" << std::endl;
    printShapeArea(c);      // 期望:78.5(不是 0!)
    printShapeArea(r);      // 期望:12

    return 0;
}
