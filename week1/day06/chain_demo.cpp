#include <iostream>

class Point {
public:
    Point(int x, int y) : x_(x), y_(y) {}

    void print() const {
        std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
    }

    // ========== 版本 A:返回 void(不能链式) ==========
    void moveX_A(int dx) {
        x_ += dx;
    }

    // ========== 版本 B:返回值(能"链",但每次都是复印,原对象没变) ==========
    Point moveX_B(int dx) {
        x_ += dx;
        return *this;        // 复印一份返回
    }

    // ========== 版本 C:返回引用(链式,而且改的就是原对象) ==========
    Point& moveX_C(int dx) {
        x_ += dx;
        return *this;        // 把自己本人的引用返回
    }

    Point& moveY_C(int dy) {
        y_ += dy;
        return *this;
    }

private:
    int x_, y_;
};

int main() {
    std::cout << "=== 版本 A:返回 void ===" << std::endl;
    Point pa(0, 0);
    pa.moveX_A(1);
    pa.moveX_A(2);      // 只能一次一次调,不能"接着来"
    pa.print();          // (3, 0)
    // pa.moveX_A(1).moveX_A(2);   // ❌ 编译报错:void 后面不能再点方法

    std::cout << "\n=== 版本 B:返回值 ===" << std::endl;
    Point pb(0, 0);
    pb.moveX_B(1).moveX_B(2);   // 能链式,但注意接下来
    pb.print();
    // ⚠️ pb 只被 moveX_B(1) 那一次改了(x 变成 1)
    // 后面的 .moveX_B(2) 是在"复印件"上改的,和 pb 无关
    // 输出会是 (1, 0),不是 (3, 0)

    std::cout << "\n=== 版本 C:返回引用 ===" << std::endl;
    Point pc(0, 0);
    pc.moveX_C(1).moveY_C(2).moveX_C(3);   // 链式调用,每一步都作用在 pc 本身
    pc.print();          // (4, 2) - 正确的连续修改

    return 0;
}
