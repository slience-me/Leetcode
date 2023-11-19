# C++

## 1. vector

向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。



当使用 C++ 中的 `vector` 时，有许多常见的用法，以下是一些详细的列出的操作和方法：

添加`using namespace std;`可以省略`std::`

### 1.1 创建 vector

```
#include <vector>

std::vector<int> myVector; // 创建一个空的整数向量
std::vector<int> myVector(5); // 创建包含 5 个元素的整数向量，初始值为默认值（0）
std::vector<int> myVector = {1, 2, 3, 4, 5}; // 创建带有初始值的整数向量
```

### 1.2 添加和访问元素

```
myVector.push_back(6); // 在 vector 尾部添加元素 6
int size = myVector.size(); // 获取 vector 的大小
int element = myVector[2]; // 获取第三个元素（索引从 0 开始）
myVector[0] = 10; // 将第一个元素的值设置为 10
```

### 1.3 删除元素

```
myVector.pop_back(); // 删除尾部的元素
myVector.erase(myVector.begin() + 2); // 删除指定位置（这里是第三个元素）的元素
myVector.clear(); // 清空 vector
```

### 1.4 遍历 vector

#### 使用范围-based for 循环（C++11+）

```
for (int num : myVector) {
    // 使用 num
}
```

#### 使用迭代器遍历

```
for (auto it = myVector.begin(); it != myVector.end(); ++it) {
    // 使用 *it
}
```

### 1.5 检查 vector 是否为空

```
bool isEmpty = myVector.empty(); // 判断 vector 是否为空
```

### 1.6 获取 vector 的首尾元素

```
int firstElement = myVector.front(); // 获取首元素
int lastElement = myVector.back(); // 获取尾元素
```

### 1.7 向量的排序

```
std::sort(myVector.begin(), myVector.end()); // 默认升序排序
std::sort(myVector.rbegin(), myVector.rend()); // 降序排序
```

### 1.8 在指定位置插入元素

```
myVector.insert(myVector.begin() + 3, 7); // 在第四个位置（索引为 3）插入元素 7
```

### 1.9 获取指定元素的位置

```
auto it = std::find(myVector.begin(), myVector.end(), 3); // 查找值为 3 的元素
if (it != myVector.end()) {
    int index = std::distance(myVector.begin(), it); // 获取元素的索引
}
```

以上列出了 `vector` 的一些常见用法，包括创建、添加、删除、遍历、排序和其他常见操作。这些操作可以根据需要灵活地使用，并且 `vector` 还提供了其他许多有用的方法和功能。



## 2. unordered_map

unordered_map和map类似，都是存储的key-value的值，可以通过key快速索引到value。不同的是unordered_map不会根据key的大小进行排序，存储时是根据key的hash值判断元素是否相同，即unordered_map内部元素是无序的。unordered_map的底层是一个防冗余的哈希表（开链法避免地址冲突）。unordered_map的key需要定义hash_value函数并且重载operator ==

当使用 C++ 中的 `std::unordered_map` 时，以下是一些常见用法的详细列表：

### 2.1 包含头文件

```
#include <unordered_map>
```

### 2.2 创建 unordered_map

```
std::unordered_map<int, std::string> myUnorderedMap; // 创建一个空的整数到字符串的映射
std::unordered_map<int, std::string> myUnorderedMap = {{1, "one"}, {2, "two"}, {3, "three"}}; // 创建带有初始值的映射
```

### 2.3 添加和访问元素

```
myUnorderedMap[4] = "four"; // 添加键值对
std::string value = myUnorderedMap[2]; // 获取键为 2 的值
```

### 2.4 删除元素

```
myUnorderedMap.erase(3); // 删除键为 3 的键值对
myUnorderedMap.clear(); // 清空 unordered_map
```

### 2.5 遍历 unordered_map

#### 使用迭代器遍历

```
for (auto it = myUnorderedMap.begin(); it != myUnorderedMap.end(); ++it) {
    // 使用 it->first 和 it->second
}
```

#### 使用范围-based for 循环（C++11+）

```
for (const auto &pair : myUnorderedMap) {
    // 使用 pair.first 和 pair.second
}
```

### 2.6 检查 unordered_map 是否为空

```
bool isEmpty = myUnorderedMap.empty(); // 判断 unordered_map 是否为空
```

### 2.7 获取 unordered_map 的大小

```

int size = myUnorderedMap.size(); // 获取 unordered_map 的大小
```

### 2.8 检查键是否存在

```
if (myUnorderedMap.count(3) > 0) {
    // 键为 3 的元素存在
}
```

### 2.9 使用自定义的哈希函数和比较函数（可选）

`std::unordered_map` 允许使用自定义的哈希函数和键比较函数，以提供特定于类型的行为。

```
struct MyHash {
    size_t operator()(const MyType &key) const {
        // 自定义哈希函数逻辑
    }
};

struct MyEqual {
    bool operator()(const MyType &lhs, const MyType &rhs) const {
        // 自定义键比较函数逻辑
    }
};

std::unordered_map<MyType, ValueType, MyHash, MyEqual> myMap;
```

以上是关于 `std::unordered_map` 常见用法的详细列举。这些操作可以帮助您灵活地使用 `unordered_map`，并根据需要管理键值对。

### 2.10 查找键是否存在并获取对应的迭代器

```
std::unordered_map<int, std::string> myUnorderedMap = {{1, "one"}, {2, "two"}, {3, "three"}};

auto it = myUnorderedMap.find(2);
if (it != myUnorderedMap.end()) {
    // 键为 2 的元素存在
    std::string value = it->second; // 获取对应的值
} else {
    // 键为 2 的元素不存在
}
```