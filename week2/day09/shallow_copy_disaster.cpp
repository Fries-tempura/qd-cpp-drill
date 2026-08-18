#include <iostream>

class IntArray {
public:
    IntArray(int size) {
        std::cout << "  构造:分配" << std::endl;
        size_ = size;
        data_ = new int[size];
        for (int i = 0; i < size; i++) data_[i] = 0;
    }

    ~IntArray() {
        std::cout << "  析构:准备 delete[] data_ (地址 " << data_ << ")" << std::endl;
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

    IntArray b = a;    // ⚠️ 默认拷贝构造:浅拷贝!

    std::cout << "a[0]=" << a.get(0) << ", b[0]=" << b.get(0) << std::endl;

    // 出 main 时,先 b 析构,再 a 析构 → 两次 delete 同一块内存 → 崩溃
    return 0;
}
