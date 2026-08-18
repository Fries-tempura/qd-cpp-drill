#include <iostream>

class IntArray {
public:
    // ============ ① 普通构造 ============
    IntArray(int size) {
        std::cout << "① 普通构造 (size=" << size << ")" << std::endl;
        size_ = size;
        data_ = new int[size];
        for (int i = 0; i < size; i++) data_[i] = 0;
    }

    // ============ ② 拷贝构造(Rule of 3 第一个) ============
    IntArray(const IntArray& other) {
        std::cout << "② 拷贝构造" << std::endl;
        size_ = other.size_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    // ============ ③ 拷贝赋值(Rule of 3 第二个) ============
    IntArray& operator=(const IntArray& other) {
        std::cout << "③ 拷贝赋值" << std::endl;

        // 步骤 1:自赋值检查
        if (this == &other) {
            return *this;
        }

        // 步骤 2:释放旧资源
        delete[] data_;

        // 步骤 3:分配新资源
        size_ = other.size_;
        data_ = new int[size_];

        // 步骤 4:复制内容
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }

        // 步骤 5:返回自己
        return *this;
    }

    // ============ ④ 析构函数(Rule of 3 第三个) ============
    ~IntArray() {
        std::cout << "④ 析构 (释放 " << size_ << " 个 int)" << std::endl;
        delete[] data_;
    }

    // 简单方法
    void set(int index, int value) { data_[index] = value; }
    int get(int index) const { return data_[index]; }
    int size() const { return size_; }

private:
    int* data_;
    int size_;
};

int main() {
    std::cout << "\n=== 测试 1:普通构造 ===" << std::endl;
    IntArray a(3);
    a.set(0, 100);

    std::cout << "\n=== 测试 2:拷贝构造 (定义 b 用 a 初始化) ===" << std::endl;
    IntArray b = a;              // 拷贝构造被调用

    std::cout << "\n=== 测试 3:拷贝赋值 (c 已存在,变成 a) ===" << std::endl;
    IntArray c(5);               // 先构造一个 size=5 的 c
    c = a;                       // 拷贝赋值被调用,c 变成 size=3

    std::cout << "\n=== 测试 4:自赋值 (a = a) ===" << std::endl;
    a = a;                       // 自赋值,不应该有事

    std::cout << "\n=== 测试 5:改一个不影响另一个 ===" << std::endl;
    a.set(0, 999);
    std::cout << "  a[0]=" << a.get(0) << ", b[0]=" << b.get(0)
              << ", c[0]=" << c.get(0) << std::endl;

    std::cout << "\n=== main 结束,析构开始 ===" << std::endl;
    return 0;
}
