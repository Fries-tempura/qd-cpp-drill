#include <iostream>
#include <utility>  // std::move

template<typename T>
class MySharedPtr {
private:
    // 嵌套类:控制块,只属于 MySharedPtr 内部用
    struct ControlBlock {
        int count;
    };

    T*            ptr_;   // 指向真正的对象
    ControlBlock* ctrl_;  // 指向堆上的控制块

public:
    // ============================================================
    // TODO 1: 构造函数
    //   - 接管原始指针 p(默认 nullptr)
    //   - 如果 p 不是 nullptr,在堆上 new 一个 ControlBlock,count 初始化为 1
    //   - 如果 p 是 nullptr,ctrl_ 也设为 nullptr(不用开控制块)
    // ============================================================
    explicit MySharedPtr(T* p = nullptr) {
        ptr_=p;
        if(p){
            ctrl_=new ControlBlock{1};
        }
        else{
            ctrl_=nullptr;
        }
    }


    // ============================================================
    // TODO 2: 析构函数
    //   - 如果 ctrl_ 非空:
    //       * --ctrl_->count
    //       * 如果 count 归 0,delete ptr_ 和 delete ctrl_
    //   - 如果 ctrl_ 是空,什么都不用做
    // ============================================================
    ~MySharedPtr() {
        if(ctrl_){
            --ctrl_->count;
            if(ctrl_->count==0){
                delete ptr_;
                delete ctrl_;
            }
        }
    }

    // TODO 3: 拷贝构造
    MySharedPtr(const MySharedPtr& other) {
        ptr_  = other.ptr_;         // ← 抄源对象的指针
        ctrl_ = other.ctrl_;        // ← 抄源对象的控制块指针
        if (ctrl_) {                // ← 特判:控制块可能是空
          ctrl_->count++;
        }
  }
    // TODO 4: 拷贝赋值
        MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
          // Step 1: 释放旧的(跟析构一样的逻辑)
            if (ctrl_) {
              --ctrl_->count;
                if (ctrl_->count == 0) {
                    delete ptr_;
                    delete ctrl_;
                } 
            }
  
            // Step 2: 抄新的(跟拷贝构造一样的逻辑)
            ptr_  = other.ptr_;
            ctrl_ = other.ctrl_;
            if (ctrl_) {
                ctrl_->count++;
            }
        } 
        return *this;
    }


    // TODO 5: 移动构造
    MySharedPtr(MySharedPtr&& other) noexcept {
        ptr_  = other.ptr_;         // ← 偷指针
        ctrl_ = other.ctrl_;        // ← 偷控制块
        other.ptr_  = nullptr;      // ← 把 other 清空(否则它析构会 delete!)
        other.ctrl_ = nullptr;
        // 注意:没有 count++!
    }
    // TODO 6: 移动赋值
    MySharedPtr& operator=(MySharedPtr&& other) noexcept {
        if (this != &other) {
          // Step 1: 释放旧的(跟拷贝赋值里前半段一模一样,你自己抄)
            if (ctrl_) {
              --ctrl_->count;
              if (ctrl_->count == 0) { delete ptr_; delete ctrl_; }
            }
  
          // Step 2: 偷 other 的(跟 TODO 5 移动构造里的 4 行一模一样,你自己抄)
          ptr_  = other.ptr_;
          ctrl_ = other.ctrl_;
          other.ptr_  = nullptr;
          other.ctrl_ = nullptr;
        }
        return *this;
    } 


    // -------- 辅助函数(已经给你,不用改) --------
    T* get() const { return ptr_; }
    int use_count() const { return ctrl_ ? ctrl_->count : 0; }
};

// -------------------- 测试代码(不要改) --------------------
struct Widget {
    int id;
    Widget(int i) : id(i) { std::cout << "  Widget(" << id << ") 构造\n"; }
    ~Widget()             { std::cout << "  Widget(" << id << ") 析构\n"; }
};

int main() {
    std::cout << "=== 阶段 1:创建 p1 ===\n";
    {
        MySharedPtr<Widget> p1(new Widget(1));
        std::cout << "p1.get()        = " << p1.get()        << " (应该非 0)\n";
        std::cout << "p1.use_count()  = " << p1.use_count()  << " (应该是 1)\n";

        std::cout << "\n=== 阶段 2:p1 即将离开作用域 ===\n";
    }  // ← p1 在这里析构,应该看到 Widget(1) 析构
    std::cout << "出作用域了(上面应该看到 Widget(1) 析构)\n";

    std::cout << "\n=== 阶段 3:空指针的 MySharedPtr ===\n";
    {
        MySharedPtr<Widget> p_empty;   // 用默认 nullptr 构造
        std::cout << "p_empty.get()        = " << p_empty.get()       << " (应该是 0)\n";
        std::cout << "p_empty.use_count()  = " << p_empty.use_count() << " (应该是 0)\n";
    }  // ← p_empty 析构,什么都不应该发生(没有 Widget 析构日志)
    std::cout << "空指针版本出作用域了(上面不应该有任何 Widget 析构)\n";

    std::cout << "\n=== 阶段 4:拷贝构造 p2 = p1 ===\n";
    {
        MySharedPtr<Widget> p1(new Widget(4));
        std::cout << "初始 p1.use_count() = " << p1.use_count() << " (应该是 1)\n";

        MySharedPtr<Widget> p2 = p1;   // ← 拷贝构造!
        std::cout << "拷贝后 p1.use_count() = " << p1.use_count() << " (应该是 2)\n";
        std::cout << "拷贝后 p2.use_count() = " << p2.use_count() << " (应该是 2)\n";
        std::cout << "p1.get() == p2.get() ? " << (p1.get() == p2.get() ? "true" : "false")
                  << " (应该是 true,两人指同一个 Widget)\n";

        std::cout << "\n=== 阶段 5:内部作用域再拷贝一份 ===\n";
        {
            MySharedPtr<Widget> p3 = p1;
            std::cout << "内部 count = " << p1.use_count() << " (应该是 3)\n";
        }  // ← p3 析构,count 应该回到 2
        std::cout << "出内部作用域后 count = " << p1.use_count() << " (应该是 2)\n";

        std::cout << "\n(阶段 4/5 结束,p1 和 p2 即将析构)\n";
    }  // ← p1、p2 依次析构,最后一个才 delete Widget(4)
    std::cout << "阶段 4/5 出作用域(上面应该只看到一次 Widget(4) 析构)\n";

    std::cout << "\n=== 阶段 6:拷贝赋值 p2 = p1 ===\n";
    {
        MySharedPtr<Widget> p1(new Widget(6));
        MySharedPtr<Widget> p2(new Widget(7));
        std::cout << "赋值前 p1.count=" << p1.use_count() << " p2.count=" << p2.use_count() << "\n";
        std::cout << "-- 现在执行 p2 = p1,应该看到 Widget(7) 被析构 --\n";
        p2 = p1;   // ← 拷贝赋值!p2 原来的 Widget(7) 应该被删
        std::cout << "赋值后 p1.count=" << p1.use_count() << " (应该是 2)\n";
        std::cout << "赋值后 p2.count=" << p2.use_count() << " (应该是 2)\n";
        std::cout << "p1.get() == p2.get() ? " << (p1.get() == p2.get() ? "true" : "false")
                  << " (应该是 true)\n";
    }
    std::cout << "阶段 6 出作用域(应该看到 Widget(6) 析构)\n";

    std::cout << "\n=== 阶段 7:移动构造 p2 = std::move(p1) ===\n";
    {
        MySharedPtr<Widget> p1(new Widget(8));
        std::cout << "移动前 p1.count = " << p1.use_count() << " (应该是 1)\n";

        MySharedPtr<Widget> p2 = std::move(p1);   // ← 移动构造!
        std::cout << "移动后 p1.get()       = " << p1.get()       << " (应该是 0)\n";
        std::cout << "移动后 p1.use_count() = " << p1.use_count() << " (应该是 0)\n";
        std::cout << "移动后 p2.get()       非 0? " << (p2.get() != nullptr ? "true" : "false") << "\n";
        std::cout << "移动后 p2.use_count() = " << p2.use_count() << " (应该还是 1,不变!)\n";
    }
    std::cout << "阶段 7 出作用域(应该只看到一次 Widget(8) 析构)\n";

    std::cout << "\n=== 阶段 8:移动赋值 p2 = std::move(p1) ===\n";
    {
        MySharedPtr<Widget> p1(new Widget(9));
        MySharedPtr<Widget> p2(new Widget(10));
        std::cout << "-- 现在执行 p2 = std::move(p1),应该看到 Widget(10) 被析构 --\n";
        p2 = std::move(p1);   // ← 移动赋值!
        std::cout << "赋值后 p1.get()       = " << p1.get()       << " (应该是 0)\n";
        std::cout << "赋值后 p1.use_count() = " << p1.use_count() << " (应该是 0)\n";
        std::cout << "赋值后 p2.use_count() = " << p2.use_count() << " (应该是 1,不变!)\n";
    }
    std::cout << "阶段 8 出作用域(应该看到 Widget(9) 析构)\n";

    std::cout << "\n=== main 结束 ===\n";
    return 0;
}
