#include <iostream>
#include <cstdio>

// TODO: 在这里写你的 FileHandle 类
// 需要:
//   - 私有成员 FILE* fp_
//   - 构造函数 FileHandle(const char* path, const char* mode)
//       * 调 fopen 打开文件,存到 fp_
//       * 如果失败,打印一句错误(fp_ 会是 nullptr)
//   - 析构函数 ~FileHandle()
//       * 如果 fp_ 不是 nullptr,调 fclose 关闭
//       * 打印一句 "FileHandle closed"
//   - 方法 void write(const char* s)
//       * 用 fprintf 写到文件
//   - 方法 bool is_open() const
//       * 返回 fp_ != nullptr
//   - ★ 禁止拷贝构造和拷贝赋值(用 = delete)
class FileHandle{
    public:
        FileHandle(const char* path, const char* mode){
            fp_=fopen(path,mode);
            if(fp_==nullptr){
                std::cout<<"错误(fp_ 会是 nullptr)"<<std::endl;
            }
        }
        ~FileHandle(){
            if(fp_!=nullptr){
                fclose(fp_);
                std::cout<<"FileHandle closed"<<std::endl;
            } else {
                std::cout << "FileHandle destroyed (no file to close)" << std::endl;
            }
        }
        void write(const char* s){
            fprintf(fp_,"%s",s);
        }
        bool is_open() const{
            return fp_!=nullptr;
        }
         // ★ 禁止拷贝构造
        FileHandle(const FileHandle&) = delete;
        // ★ 禁止拷贝赋值
        FileHandle& operator=(const FileHandle&) = delete;
    private:
        FILE* fp_;
};

int main() {
    std::cout << "=== 测试 1:正常打开写入 ===" << std::endl;
    {
        FileHandle f("test.txt", "w");
        if (f.is_open()) {
            f.write("hello from FileHandle\n");
            f.write("second line\n");
        }
    }   // ← 出作用域,f 自动析构 → 文件自动关闭

    std::cout << "\n=== 测试 2:打开失败 ===" << std::endl;
    {
        FileHandle f("/nonexistent/path/file.txt", "r");
        std::cout << "is_open: " << (f.is_open() ? "yes" : "no") << std::endl;
    }   // ← 析构时不应该崩(因为 fp_ 是 nullptr)

    std::cout << "\n=== 测试 3:禁止拷贝 ===" << std::endl;
    // 下面两行如果解开注释,应该编译报错
    // FileHandle f1("a.txt", "w");
    // FileHandle f2 = f1;      // ← 应该编译错

    std::cout << "\n=== 测试结束 ===" << std::endl;
    return 0;
}
