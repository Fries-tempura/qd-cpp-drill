# QD C++ Drill

> 12-month C++ learning journey targeting **Quantitative Developer** roles at Chinese hedge funds.
>
> 面向大陆量化私募 C++ 开发岗的 12 个月冲刺训练。

**Author**: Audery Liu · MSc Cybersecurity @ NTU Singapore (2026-08 ~ 2027-08)
**Started**: 2026-07-20
**Target**: 九坤投资(Ubiquant)C++ 开发岗 · 2027 暑期实习 → 秋招 return offer

---

## 📊 进度快照

| 项目 | 状态 |
|------|------|
| **LeetCode 累计** | 19 题(Easy 主) |
| **手撕清单** | 2 / 7 完成 |
| **学习周数** | Week 1 ~ Week 3(Week 4 恢复中) |

### 手撕清单进度

- [x] MyUniquePtr(移动语义)· `week3/day18/`
- [x] MySharedPtr(引用计数)· `week3/day19/`
- [ ] MyVector(扩容 + move)
- [ ] MyString(Rule of 3)
- [ ] ThreadPool(线程池)
- [ ] SPSCQueue(无锁队列)
- [ ] LRUCache(list + hashmap)

---

## 📂 仓库结构

```
cpp-drill/
├── week1/          C++ 基础(环境、引用、const、重载、namespace、类)
├── week2/          类深入(构造/拷贝/RAII/运算符/继承/虚函数)
├── week3/          内存管理 + 智能指针
│   ├── day15/      new/delete + smart array
│   ├── day16/      std::shared_ptr
│   ├── day17/      std::weak_ptr
│   ├── day18/      ⭐ MyUniquePtr 手撕
│   └── day19/      ⭐ MySharedPtr 手撕
└── week4/          栈 + 队列 + MyVector(进行中)
```

---

## 🛠️ 编译方式

标准编译:

```bash
clang++ -std=c++20 -Wall -Wextra -O2 -o build/name file.cpp
```

带 AddressSanitizer(调试内存问题):

```bash
clang++ -std=c++20 -fsanitize=address -g -o build/name file.cpp
```

**注意**:二进制建议输出到 `build/` 目录,该目录已被 `.gitignore` 排除。

---

## 📖 相关文档

- 12 个月完整计划:见 `~/Documents/NTU/QD/QD_12_month_plan.md`(未公开)
- 错题笔记:`error_notes.md`(未公开)

---

## 🎯 目标节奏(2026-08-18 修订)

- **8 题 LeetCode / 周**
- **1 个手撕项目模块 / 周**(核心项目分 2-4 周完成)
- **主战场**:2027-05 投九坤暑期实习

---

_This repo is a daily learning log — commit frequency reflects study consistency, not code quality on every commit. Highlight projects (ThreadPool, SPSCQueue, MatchingEngine) will be split into standalone repos as they're built._
