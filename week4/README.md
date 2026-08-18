# Week 4 (2026-08-10 ~ 2026-08-16)

**主题**:栈 + 队列 + 手撕 `MyVector<T>`

**Week 3 结束状态**:
- LeetCode 累计 19 题
- 手撕清单 2/7 完成(MyUniquePtr、MySharedPtr)
- Q1 移动语义有弱点,本周通过 MyVector 巩固

**Week 4 目标**:
- LeetCode 累计 **39 题**(+20)
- 手撕清单 3/7(加 MyVector)
- 掌握栈/队列的应用套路(单调栈是重点)

---

## 日程

### Day 21 · 周一 8/10 · 栈入门

**C++ 主题**:`std::stack` 用法 + 后进先出思想

**LeetCode 3 题**:
- [x] #20 有效的括号(周日已做,列在这里是承接关系)
- [ ] #150 逆波兰表达式求值
- [ ] #232 用栈实现队列

**产出**:`day21/stack_demo.cpp` + LeetCode 提交

---

### Day 22 · 周二 8/11 · 队列 + 双端队列

**C++ 主题**:`std::queue` / `std::deque` 用法

**LeetCode 3 题**:
- [ ] #225 用队列实现栈
- [ ] #71 简化路径
- [ ] #155 最小栈

**产出**:`day22/queue_demo.cpp` + LeetCode 提交

---

### Day 23 · 周三 8/12 · 单调栈(重点)

**C++ 主题**:单调栈概念 + 何时用(找"下一个更大/更小")

**LeetCode 4 题**:
- [ ] #496 下一个更大元素 I
- [ ] #739 每日温度
- [ ] #503 下一个更大元素 II(循环数组)
- [ ] #84 柱状图中最大的矩形(Hard,可选,做不完顺延)

**产出**:`day23/monotonic_stack_demo.cpp` + 提交

---

### Day 24 · 周四 8/13 · STL vector 底层

**C++ 主题**:
- `std::vector` 内部结构(3 个指针 or 指针+容量+大小)
- 扩容策略(2 倍 vs 1.5 倍)
- 迭代器失效场景

**LeetCode 3 题**(栈队列综合):
- [ ] #394 字符串解码
- [ ] #1047 删除字符串中所有相邻重复项
- [ ] 自选 1 道 Medium 复习

**产出**:`day24/vector_internals.md`(概念笔记)

---

### Day 25 · 周五 8/14 · 手撕 MyVector 上半

**C++ 主题**:开始实现 `MyVector<T>`

**手撕任务(TODO 1-4)**:
- TODO 1: 构造函数 + 成员变量(data_, size_, capacity_)
- TODO 2: 析构函数(delete[] data_)
- TODO 3: 拷贝构造 + 拷贝赋值(深拷贝)
- TODO 4: `push_back` 基础版(容量够时直接放)

**LeetCode 3 题**(可选 1 道回顾):
- [ ] 自选栈队列相关

**产出**:`day25/my_vector_exercise.cpp`(部分完成)

---

### Day 26 · 周六 8/15 · 手撕 MyVector 下半

**C++ 主题**:完成 `MyVector<T>` + 测试

**手撕任务(TODO 5-8)**:
- TODO 5: 移动构造 + 移动赋值(**顺便巩固 Q1 弱点**)
- TODO 6: `push_back` 扩容版(容量满时 realloc)
- TODO 7: `operator[]` + `size()` / `capacity()`
- TODO 8: 完整测试(观察扩容过程 + 拷贝/移动次数)

**LeetCode 2 题**:
- [ ] 1 新(自选栈队列 or 数组)
- [ ] 1 回顾(从本周挑最不熟的)

**产出**:`day26/my_vector_exercise.cpp`(完整版)+ 手撕清单进度 3/7

---

### Day 27 · 周日 8/16 · Week 4 复盘

- 上午:休息
- 下午:
  - 15 分钟周复盘(quiz 5 题,同上周格式)
  - LeetCode 2 题(1 新 + 1 回顾)
- 晚上:30 分钟 Week 5 计划

**产出**:更新 `error_notes.md` + Week 5 方向

---

## 本周关键节点

- Day 23 单调栈是重难点,可能需要多花时间
- Day 25-26 MyVector 是重头戏,如果 Day 26 写不完可以顺延到周日上午
- Q1 移动语义弱点:在 Day 26 TODO 5 完成后自测(在心里说清楚"MyVector 什么时候会触发移动")

## 一周总量对照

- LeetCode:20 题(3+3+4+3+3+2+2)
- C++ 手撕:1 个(MyVector)
- 手撕清单进度:2/7 → 3/7
