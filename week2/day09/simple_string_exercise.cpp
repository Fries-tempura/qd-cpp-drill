#include <iostream>
#include <cstring>

// TODO: 在这里写你的 SimpleString 类
// 需要:
//   - 私有成员 char* data_ 和 int size_
//   - 构造函数 SimpleString(const char* s)
//   - 拷贝构造 SimpleString(const SimpleString& other)
//   - 拷贝赋值 SimpleString& operator=(const SimpleString& other)
//   - 析构函数 ~SimpleString()
//   - print() const 方法
//   - size() const 方法
class SimpleString{
    public:
        SimpleString(const char* s){
            size_=(int)strlen(s);
            data_=new char[size_+1];
            strcpy(data_,s);
        }
        SimpleString(const SimpleString& other){
            size_=other.size_;
            data_=new char[other.size_+1];
            strcpy(data_,other.data_);
        }
        SimpleString& operator=(const SimpleString& other){
            if(this==&other){
                return *this;
            } 
            delete[] data_;
            size_=other.size_;
            data_=new char[other.size_+1];
            strcpy(data_,other.data_);
            return *this;
        }
        ~SimpleString(){
            delete[] data_;
        }
        void print() const{
            std::cout<<"当前字符串"<<data_<<std::endl;
        }
        int size() const{
            return size_;
        }
    private:
        char* data_;
        int size_;
};

int main() {
    std::cout << "=== 测试 1:普通构造 ===" << std::endl;
    SimpleString s1("hello");
    s1.print();
    std::cout << "size = " << s1.size() << std::endl;

    std::cout << "\n=== 测试 2:拷贝构造 ===" << std::endl;
    SimpleString s2 = s1;
    s2.print();

    std::cout << "\n=== 测试 3:拷贝赋值 ===" << std::endl;
    SimpleString s3("initial");
    s3 = s1;
    s3.print();

    std::cout << "\n=== 测试 4:自赋值 ===" << std::endl;
    s1 = s1;
    s1.print();

    std::cout << "\n=== 测试结束,自动析构 ===" << std::endl;
    return 0;
}


//hello
//01234
//size=5
//但是其实最后还有/0需要复制