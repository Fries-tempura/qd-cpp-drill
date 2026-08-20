  #include <unordered_map>

  // 1. 定义 (key=int, value=int)
  std::unordered_map<int, int> m;

  // 2. 插入 / 更新
  m[1] = 3;               // 直接用 [] 赋值 (key=1 → value=3)
  m.insert({2, 4});       // 另一种写法 (等价 m[2]=4)

  // 3. 查询
  int v = m[1];           // ⚠️  坑: 如果 key 不存在,会自动创建默认值 0 并返回

  // 4. 判断 key 是否存在 (你最常用的)
  if (m.count(1) > 0) {   // count 返回 0 或 1 (unordered_map 里 key 唯一)
      // 存在
  }
  if (m.find(1) != m.end()) {  // 另一种等价写法
      // 存在
  }

  // 5. 遍历 (C++17)
  for (auto& [k, v] : m) {
      std::cout << k << " -> " << v << '\n';
  }
   关于查询；
  
  姿势 A:先 count 后 推荐,直观

  if (m.count(x)) {           // 存在?
      int v = m[x];           // 安全,已确认存在
      // 用 v 干活
  } else {
      // 不存在的分支
  }

  姿势 B:用 find(更高效,一次查询)

  auto it = m.find(x);
  if (it != m.end()) {        // 存在?
      int v = it->second;     // it->second 是值
  } else {
      // 不存在
  }
