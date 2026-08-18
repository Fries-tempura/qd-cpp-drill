#include <iostream>

class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}

    // 已经给你的:operator+
    Point operator+(const Point& other) const {
        return Point(x_ + other.x_, y_ + other.y_);
    }

    // TODO 1:重载 operator- (点相减)
    //   例:Point(5, 8) - Point(1, 2) = Point(4, 6)
    Point operator-(const Point& other) const{
        return Point(x_-other.x_,y_-other.y_);
    }

    // TODO 2:重载 operator== (点相等比较)
    //   x_ 和 y_ 都相等 → 返回 true,否则 false
    bool operator==(const Point& other) const{
        return (x_==other.x_)&&(y_==other.y_);
    }

    // TODO 3:重载 operator!= (点不相等比较)
    //   直接用 !(自己 == other) 就行
    bool operator!=(const Point& other)const{
        return !(*this==other);
    }

    void print() const {
        std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
private:
    int x_, y_;
};
std::ostream& operator<<(std::ostream& os,const Point& p){
    os<<"("<<p.x_<<","<<p.y_<<")";
    return os;
}

int main() {
    Point p1(3, 4);
    Point p2(1, 2);

    std::cout << "=== 测试 + ===" << std::endl;
    Point p3 = p1 + p2;
    p3.print();                     // 期望:(4, 6)

    std::cout << "\n=== 测试 - ===" << std::endl;
    Point p4 = p1 - p2;
    p4.print();                     // 期望:(2, 2)

    std::cout << "\n=== 测试 == 和 != ===" << std::endl;
    Point p5(3, 4);
    Point p6(0, 0);
    std::cout << "p1 == p5: " << (p1 == p5) << " (期望 1)" << std::endl;
    std::cout << "p1 == p6: " << (p1 == p6) << " (期望 0)" << std::endl;
    std::cout << "p1 != p6: " << (p1 != p6) << " (期望 1)" << std::endl;
    std::cout << "\n=== 测试 << ===" << std::endl;
    std::cout << "p1 = " << p1 << std::endl;
    std::cout << "p1 + p2 = " << (p1 + p2) << std::endl;

    return 0;
}
