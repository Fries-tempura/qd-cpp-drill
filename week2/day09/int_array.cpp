#include <iostream>

class IntArray {
public:
    // ============ 普通构造函数 ============
    IntArray(int size) {
        std::cout << "  构造:分配 " << size << " 个 int" << std::endl;
        size_ = size;
        data_ = new int[size];         // 动态分配 size 个 int 的数组

        // 初始化为 0
        for (int i = 0; i < size; i++) {
            data_[i] = 0;
        }
    }

    // ============ 析构函数 ============
    ~IntArray() {
        std::cout << "  析构:释放 " << size_ << " 个 int" << std::endl;
        delete[] data_;                // 释放内存
    }

    // ============ 简单方法:设值和取值 ============
    void set(int index, int value) {
        data_[index] = value;
    }

    int get(int index) const {
        return data_[index];
    }

    int size() const {
        return size_;
    }

private:
    int* data_;                        // 指向动态内存的指针
    int size_;                         // 数组大小
};

int main() {
    IntArray a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);

    std::cout << "a[0]=" << a.get(0) << ", a[1]=" << a.get(1) << ", a[2]=" << a.get(2) << std::endl;

    return 0;
}
