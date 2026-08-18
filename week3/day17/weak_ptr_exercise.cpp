#include <iostream>
#include <memory>

class Node {
public:
    Node()  { std::cout << "  Node 构造" << std::endl; }
    ~Node() { std::cout << "  Node 析构" << std::endl; }

    // TODO 1:把 parent 改成 weak_ptr<Node>
    std::weak_ptr<Node> parent;    // ← 循环引用的元凶
    std::shared_ptr<Node> child;
};

int main() {
    std::cout << "=== 阶段 1:创建父子节点 ===" << std::endl;
    auto p = std::make_shared<Node>();
    auto c = std::make_shared<Node>();

    p->child = c;
    c->parent = p;

    std::cout << "p 引用计数: " << p.use_count() << std::endl;   // 应该是 2
    std::cout << "c 引用计数: " << c.use_count() << std::endl;   // 应该是 2

    std::cout << "\n=== 阶段 2:main 结束(观察析构) ===" << std::endl;
    // 如果 parent 是 shared_ptr:两个 Node 都不会析构(泄漏!)
    // 如果 parent 是 weak_ptr:两个 Node 都会析构
    return 0;
}
