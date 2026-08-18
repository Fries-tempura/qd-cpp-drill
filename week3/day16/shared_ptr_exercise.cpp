#include <iostream>
#include <memory>
#include <string>

// 一个数据类
class Data {
public:
    Data(const std::string& content) : content_(content) {
        std::cout << "  Data 构造: " << content_ << std::endl;
    }
    ~Data() {
        std::cout << "  Data 析构: " << content_ << std::endl;
    }
    void print() const {
        std::cout << "  内容: " << content_ << std::endl;
    }
private:
    std::string content_;
};

// TODO:写你的 Cache 类
// 需要:
//   - 私有成员:std::shared_ptr<Data> data_
//   - 构造函数 Cache(const std::string& content)
//       * 用 make_shared 创建 Data
//   - 方法 std::shared_ptr<Data> get() const
//       * 返回 data_(shared_ptr 会自动 +1 计数)
//   - 方法 int useCount() const
//       * 返回 data_.use_count()
class Cache{
public:
    Cache(const std::string& content){
        data_=std::make_shared<Data>(content);
    }
    std::shared_ptr<Data> get() const{
        return data_;
    }
    int useCount() const{
        return data_.use_count();
    }
private:
    std::shared_ptr<Data> data_;
};


int main() {
    std::cout << "=== 创建 Cache ===" << std::endl;
    Cache cache("hello world");
    std::cout << "初始计数: " << cache.useCount() << std::endl;

    std::cout << "\n=== 主线程 get 一份 ===" << std::endl;
    {
        auto data1 = cache.get();
        std::cout << "get 后计数: " << cache.useCount() << std::endl;
        data1->print();

        std::cout << "\n=== '用户' 再 get 一份 ===" << std::endl;
        auto data2 = cache.get();
        std::cout << "第二次 get 后计数: " << cache.useCount() << std::endl;
    }   // ← data1, data2 析构

    std::cout << "\n=== 所有 get 都用完 ===" << std::endl;
    std::cout << "现在计数: " << cache.useCount() << std::endl;

    std::cout << "\n=== main 结束前 ===" << std::endl;
    return 0;
}
