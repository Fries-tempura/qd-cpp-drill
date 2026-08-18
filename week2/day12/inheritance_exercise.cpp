#include <iostream>
#include <string>

// TODO 1:写父类 Shape
//   - protected 成员:std::string name_
//   - 构造函数:Shape(const std::string& name)
//   - public 方法:void describe() const  → 打印 "我是形状 [name_]"
class Shape{
public:
    Shape(const std::string& name):name_(name){}
    void describe() const{
        std::cout<<"我是形状["<<name_<<"]"<<std::endl;
    }
protected:
    std::string name_;
};
// TODO 2:写子类 Circle(继承 Shape)
//   - private 成员:double radius_
//   - 构造函数:Circle(const std::string& name, double radius)
//       * 初始化列表里先调 Shape(name),再初始化 radius_
//   - public 方法:double area() const  → 返回 3.14 * radius_ * radius_
class Circle:public Shape{
public:
    Circle(const std::string&name,double radius):Shape(name),radius_(radius){}
    double area() const{
        return 3.14*radius_*radius_;
    }
private:
    double radius_;
};
// TODO 3:写子类 Rectangle(继承 Shape)
//   - private 成员:double width_, height_
//   - 构造函数:Rectangle(const std::string& name, double w, double h)
//   - public 方法:double area() const  → 返回 width_ * height_
class Rectangle:public Shape{
public:
    Rectangle(const std::string& name,double w,double h):Shape(name),width_(w),height_(h){}
    double area() const{
        return width_*height_;
    }
private:
    double width_;
    double height_;
};

int main() {
    std::cout << "=== 创建 Circle ===" << std::endl;
    Circle c("圆1", 5.0);
    c.describe();                                  // 从 Shape 继承
    std::cout << "面积 = " << c.area() << std::endl;   // Circle 自己的

    std::cout << "\n=== 创建 Rectangle ===" << std::endl;
    Rectangle r("矩形1", 3.0, 4.0);
    r.describe();                                  // 从 Shape 继承
    std::cout << "面积 = " << r.area() << std::endl;

    return 0;
}
