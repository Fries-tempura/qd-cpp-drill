#include <iostream>

class MyContainer {
public:
    // ================ 在类里定义类型 ================
    // 这是一个"内部类型":Position 只属于 MyContainer
    using Position = int;             // 用 using 定义类型别名

    // 也可以用 typedef(老写法,和 using 等价):
    // typedef int Position;

    // 甚至可以定义一个内部结构体
    struct Item {
        int id;
        std::string name;
    };

    // ================ 使用这些类型 ================
    Position getFirstPosition() const {
        return 0;
    }

    void addItem(Item item) {
        std::cout << "Added item " << item.id << ": " << item.name << std::endl;
    }
};

int main() {
    MyContainer c;

    // 从外面用类型,必须写 类名::类型
    MyContainer::Position pos = c.getFirstPosition();
    std::cout << "Position: " << pos << std::endl;

    MyContainer::Item item{42, "apple"};
    c.addItem(item);

    return 0;
}
