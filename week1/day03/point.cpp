#include <iostream>
#include <cmath>   // for std::sqrt

class Point {
public:
    // 构造函数:创建 Point 时初始化 x 和 y
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}
    Point():x(0),y(0){}
    // TODO 1:实现 print(),不修改成员 → 你觉得该加 const 吗?
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

    // TODO 2:实现 move(),修改成员 → 你觉得该加 const 吗?
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    // TODO 3:实现 distance_to(other),计算到另一点的距离,不修改成员
    double distance_to(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    // TODO 4:提供 get_x() 和 get_y(),只读访问 x 和 y
    int get_x() const{
        return x;
    }

    int get_y() const{
        return y;
    }

private:                // private 表示外面不能直接访问
    int x;
    int y;
};

int main() {
    Point p1(0, 0);
    Point p2(3, 4);

    p1.print();
    p2.print();

    std::cout << "distance = " << p1.distance_to(p2) << std::endl;

    p1.move(1, 1);
    p1.print();

    // ---- 关键测试:const 对象 ----
    const Point cp(10, 20);
    cp.print();                             // 应该能过(如果 print 是 const)
    std::cout << "cp.x = " << cp.get_x() << std::endl;   // 应该能过
    // cp.move(1, 1);                       // 试着解注释:应该报错
    Point origin;
    return 0;
}
