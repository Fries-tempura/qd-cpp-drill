#include <iostream>

class IntArray {
public:
    // 普通构造
    IntArray(int size) {
        std::cout << "  普通构造" << std::endl;
        size_ = size;
        data_ = new int[size];
        for (int i = 0; i < size; i++) data_[i] = 0;
    }

    // ★ 自定义拷贝构造:深拷贝
    IntArray(const IntArray& other) {
        std::cout << "  拷贝构造(深拷贝)" << std::endl;
        size_ = other.size_;
        data_ = new int[size_];                  // 分配自己的新内存
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];           // 复制每个元素
        }
    }

    ~IntArray() {
        std::cout << "  析构:释放地址 " << data_ << std::endl;
        delete[] data_;
    }

    void set(int index, int value) { data_[index] = value; }
    int get(int index) const { return data_[index]; }

private:
    int* data_;
    int size_;
};

int main() {
    IntArray a(3);
    a.set(0, 10);

    IntArray b = a;    // ✅ 现在调用我们自己写的拷贝构造 → 深拷贝

    std::cout << "a[0]=" << a.get(0) << ", b[0]=" << b.get(0) << std::endl;

    b.set(0, 999);     // 改 b 不会影响 a(因为两块内存独立)
    std::cout << "改 b 后: a[0]=" << a.get(0) << ", b[0]=" << b.get(0) << std::endl;

    return 0;
    // 出 main 时:先 b 析构(释放它自己的内存),再 a 析构(释放它自己的内存)
    // 两个地址不同,不会 double-free
}
