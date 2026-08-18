#include <iostream>
#include <string>

// ============ namespace 1:交易日志 ============
namespace finance {
    void log(const std::string& msg) {
        std::cout << "[FINANCE LOG] " << msg << std::endl;
    }

    double pi = 3.14;   // finance 里的 pi(有点怪,只是为了演示)

    class Order {
    public:
        Order(int id) : id_(id) {}
        void print() const {
            std::cout << "Order #" << id_ << std::endl;
        }
    private:
        int id_;
    };
}

// ============ namespace 2:数学 ============
namespace math {
    double log(double x) {
        // 简化版:不是真的 log,只是为了演示
        return x * 0.5;
    }

    double pi = 3.14159265;    // math 里的 pi 更精确
}

int main() {
    // ---- 完整前缀:清晰,不会撞 ----
    finance::log("BUY 100 shares");
    double result = math::log(10.0);
    std::cout << "math::log(10.0) = " << result << std::endl;

    // ---- 两个 pi,值不同,靠 namespace 区分 ----
    std::cout << "finance::pi = " << finance::pi << std::endl;
    std::cout << "math::pi    = " << math::pi << std::endl;

    // ---- namespace 里的类,创建时也要加前缀 ----
    finance::Order o(42);
    o.print();

    return 0;
}
