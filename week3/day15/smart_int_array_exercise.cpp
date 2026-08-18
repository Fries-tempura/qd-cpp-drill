#include <iostream>
#include <memory>

// TODO:写你的 SmartIntArray 类
// 需要:
//   - 私有:std::unique_ptr<int[]> data_ 和 int size_
//   - 构造函数 SmartIntArray(int size)
//       * 分配 unique_ptr 管理的数组
//       * 每个元素初始化为 0
//   - void set(int index, int value)
//   - int get(int index) const
//   - int size() const
class SmartIntArray{
public:
    SmartIntArray(int size): data_(std::make_unique<int[]>(size)),size_(size){
        for(int i=0;i<size;i++){
            data_[i]=0;
        }
    }
    void set(int index, int value){
        if(index>=0&&index<size_){
            data_[index]=value;
        }
    }
    int size() const{
        return size_;
    }
    int get(int index) const{
        return data_[index];
    }
private:
    std::unique_ptr<int[]> data_;
    int size_;
};

int main() {
    SmartIntArray a(3);
    a.set(0, 10);
    a.set(1, 20);
    a.set(2, 30);

    std::cout << "size = " << a.size() << std::endl;
    std::cout << "a[0]=" << a.get(0) << ", a[1]=" << a.get(1) << ", a[2]=" << a.get(2) << std::endl;

    // ★ 关键:你没写析构!
    // 但 unique_ptr 会自动 delete[] data_
    return 0;
}
