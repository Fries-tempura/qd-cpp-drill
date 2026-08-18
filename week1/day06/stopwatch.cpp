#include <iostream>
#include <chrono>       // C++ 的时间库
#include <thread>       // for sleep

class Stopwatch {
public:
    // TODO 1:构造函数
    //   - 在初始化列表里记录"出生时间"到 start_time_
    //   - 打印一句 "Stopwatch started"
    Stopwatch() : start_time_(std::chrono::steady_clock::now()) {
        std::cout << "Stopwatch started" << std::endl;
    }

    // TODO 2:析构函数
    //   - 打印一句 "Stopwatch destroyed after X ms"(X 是活了多久)
    ~Stopwatch() {
        auto now = std::chrono::steady_clock::now();
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time_).count();
        std::cout << "Stopwatch destroyed after " << ms << " ms" << std::endl;
    }

    // 返回从出生到"现在"经过了多少毫秒(const 方法,不改成员)
    long elapsed_ms() const {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(now - start_time_).count();
    }

    // 打印当前经过的毫秒数
    void print() const {
        std::cout << "  elapsed: " << elapsed_ms() << " ms" << std::endl;
    }

private:
    std::chrono::steady_clock::time_point start_time_;   // 记录出生时刻
};

int main() {
    std::cout << "=== 场景 1:小作用域 ===" << std::endl;
    {
        Stopwatch sw;                                            // 出生
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        sw.print();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        sw.print();
    }   // ← 出大括号,sw 析构

    std::cout << "\n=== 场景 2:嵌套 ===" << std::endl;
    Stopwatch outer;
    {
        Stopwatch inner;
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }   // ← inner 先死
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    // ← 函数结束时 outer 才死

    return 0;
}
