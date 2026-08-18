#include <iostream>
#include <string>

// 两个重载:一个接左值,一个接右值
void take(const std::string& s) {
    std::cout << "拷贝版本被调用: " << s << std::endl;
}
void take(std::string&& s) {
    std::cout << "移动版本被调用: " << s << std::endl;
}

int main() {
    std::string a = "hello";

    std::cout << "--- 传左值 a ---" << std::endl;
    take(a);                    // ?

    std::cout << "--- 传右值 \"world\" ---" << std::endl;
    take(std::string("world")); // ?

    std::cout << "--- 传 std::move(a) ---" << std::endl;
    take(std::move(a));         // ?

    return 0;
}
