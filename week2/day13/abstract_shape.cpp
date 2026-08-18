#include <iostream>
#include <string>
class Shape {
public:
    Shape(const std::string& name) : name_(name) {}
    virtual ~Shape() {}                      // ★ 虚析构(即使空的也要写)

    void describe() const {
        std::cout << "我是形状[" << name_ << "]" << std::endl;
    }

    virtual double area() const = 0;         // ★ 纯虚函数
  
protected:
    std::string name_;
};

class Circle:public Shape{
public:
    Circle(const std::string& name,double r):Shape(name),r_(r){}
    double area() const override { 
        return 3.14*r_*r_;
    }
private:
    double r_;
};

class Rectangle:public Shape{
public:
    Rectangle(const std::string& name,double a,double b):Shape(name),a_(a),b_(b){}
    double area() const override { 
        return a_*b_;
    }
private:
    double a_;
    double b_;
};

int main() {
      // Shape s("原始");   // ← 这行现在应该编译报错:抽象类不能实例化,可以试试解注释验证
    Circle c("圆1", 5.0);
    Rectangle r("矩形1", 3.0, 4.0);

    // ★ 用 Shape 指针指向子类,展示多态
    Shape* shapes[] = { &c, &r };

    for (Shape* s : shapes) {
        s->describe();
        std::cout << "面积 = " << s->area() << std::endl;
    }
    return 0;
}

