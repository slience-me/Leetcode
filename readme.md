# C++

## 1. vector

向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）。跟任意其它类型容器一样，它能够存放各种类型的对象。可以简单的认为，向量是一个能够存放任意类型的动态数组。



当使用 C++ 中的 `vector` 时，有许多常见的用法，以下是一些详细的列出的操作和方法：

添加`using namespace std;`可以省略`std::`

### 1.1 创建 vector

```cpp
#include <vector>

std::vector<int> myVector; // 创建一个空的整数向量
std::vector<int> myVector(5); // 创建包含 5 个元素的整数向量，初始值为默认值（0）
std::vector<int> myVector = {1, 2, 3, 4, 5}; // 创建带有初始值的整数向量
```

### 1.2 添加和访问元素

```cpp
myVector.push_back(6); // 在 vector 尾部添加元素 6
int size = myVector.size(); // 获取 vector 的大小
int element = myVector[2]; // 获取第三个元素（索引从 0 开始）
myVector[0] = 10; // 将第一个元素的值设置为 10
```

### 1.3 删除元素

```cpp
myVector.pop_back(); // 删除尾部的元素
myVector.erase(myVector.begin() + 2); // 删除指定位置（这里是第三个元素）的元素
myVector.clear(); // 清空 vector
```

### 1.4 遍历 vector

#### 使用范围-based for 循环（C++11+）

```cpp
for (int num : myVector) {
    // 使用 num
}
```

#### 使用迭代器遍历

```cpp
for (auto it = myVector.begin(); it != myVector.end(); ++it) {
    // 使用 *it
}
```

### 1.5 检查 vector 是否为空

```cpp
bool isEmpty = myVector.empty(); // 判断 vector 是否为空
```

### 1.6 获取 vector 的首尾元素

```cpp
int firstElement = myVector.front(); // 获取首元素
int lastElement = myVector.back(); // 获取尾元素
```

### 1.7 向量的排序

```cpp
std::sort(myVector.begin(), myVector.end()); // 默认升序排序
std::sort(myVector.rbegin(), myVector.rend()); // 降序排序
```

### 1.8 在指定位置插入元素

```cpp
myVector.insert(myVector.begin() + 3, 7); // 在第四个位置（索引为 3）插入元素 7
```

### 1.9 获取指定元素的位置

```cpp
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

```cpp
#include <unordered_map>
```

### 2.2 创建 unordered_map

```cpp
std::unordered_map<int, std::string> myUnorderedMap; // 创建一个空的整数到字符串的映射
std::unordered_map<int, std::string> myUnorderedMap = {{1, "one"}, {2, "two"}, {3, "three"}}; // 创建带有初始值的映射
```

### 2.3 添加和访问元素

```cpp
myUnorderedMap[4] = "four"; // 添加键值对
std::string value = myUnorderedMap[2]; // 获取键为 2 的值
```

### 2.4 删除元素

```cpp
myUnorderedMap.erase(3); // 删除键为 3 的键值对
myUnorderedMap.clear(); // 清空 unordered_map
```

### 2.5 遍历 unordered_map

#### 使用迭代器遍历

```cpp
for (auto it = myUnorderedMap.begin(); it != myUnorderedMap.end(); ++it) {
    // 使用 it->first 和 it->second
}
```

#### 使用范围-based for 循环（C++11+）

```cpp
for (const auto &pair : myUnorderedMap) {
    // 使用 pair.first 和 pair.second
}
```

### 2.6 检查 unordered_map 是否为空

```cpp
bool isEmpty = myUnorderedMap.empty(); // 判断 unordered_map 是否为空
```

### 2.7 获取 unordered_map 的大小

```cpp

int size = myUnorderedMap.size(); // 获取 unordered_map 的大小
```

### 2.8 检查键是否存在

```cpp
if (myUnorderedMap.count(3) > 0) {
    // 键为 3 的元素存在
}
```

### 2.9 使用自定义的哈希函数和比较函数（可选）

`std::unordered_map` 允许使用自定义的哈希函数和键比较函数，以提供特定于类型的行为。

```cpp
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

```cpp
std::unordered_map<int, std::string> myUnorderedMap = {{1, "one"}, {2, "two"}, {3, "three"}};

auto it = myUnorderedMap.find(2);
if (it != myUnorderedMap.end()) {
    // 键为 2 的元素存在
    std::string value = it->second; // 获取对应的值
} else {
    // 键为 2 的元素不存在
}
```



## 3. string

`<string>` 头文件中提供了许多用于处理字符串的方法。以下是 `<string>` 头文件中一些常用的方法：

### 3.1 构造函数和赋值操作：

- **构造函数：**
  
    ```cpp
    std::string str; // 默认构造函数，创建一个空字符串
    std::string str2("Hello"); // 使用字符串常量初始化
    std::string str3(str2); // 拷贝构造函数
    std::string str4(5, 'a'); // 使用重复的字符初始化字符串
    ```
    
- **赋值操作：**
  
    ```cpp
    std::string str = "Hello";
    std::string anotherStr;
    anotherStr = str; // 赋值运算符
    anotherStr.assign("New string"); // 使用 assign 方法赋值
    anotherStr = "New value"; // 使用赋值运算符直接赋值
    ```

### 3.2 访问字符串内容：

- **访问字符：**

    ```cpp
    std::string str = "Hello";
    char ch = str[0]; // 通过下标访问字符串中的字符
    char ch2 = str.at(1); // 使用 at() 方法访问指定位置的字符
    ```

- **获取子串：**

    ```cpp
    std::string str = "Hello, World!";
    std::string substr = str.substr(7, 5); // 从索引 7 开始，长度为 5 的子串
    ```

### 3.3 修改字符串内容：

- **连接字符串：**
    ```cpp
    std::string str = "Hello";
    str += " World"; // 使用 += 运算符连接字符串
    str.append(" from C++"); // 使用 append() 方法连接字符串
    ```

- **插入和删除操作：**

    ```cpp
    std::string str = "Hello";
    str.insert(5, ", there"); // 在索引 5 处插入字符串
    str.erase(2, 3); // 从索引 2 开始删除 3 个字符
    ```

### 3.4 查询字符串信息：

- **获取长度：**

    ```cpp
    std::string str = "Hello";
    int length = str.length(); // 获取字符串长度
    ```

- **比较字符串：**

    ```cpp
    std::string str1 = "Hello";
    std::string str2 = "Hi";
    int result = str1.compare(str2); // 比较两个字符串
    ```

### 3.5 其他操作：

- **查找字符或子串：**

    ```cpp
    std::string str = "Hello, World!";
    size_t found = str.find("World"); // 查找子串的位置
    ```

- **转换为 C-style 字符串：**

    ```cpp
    std::string str = "Hello";
    const char* cStr = str.c_str(); // 转换为 C-style 字符串
    ```

这些只是 `<string>` 头文件中提供的一些常用方法。`std::string` 类型有许多其他方法可用于操作和处理字符串。

## 4. algorithm

`<algorithm>` 头文件提供了许多常用的算法和函数模板，用于在标准容器（如向量、列表、数组等）上执行各种操作。以下是一些常用的 `<algorithm>` 头文件中方法和函数模板：

### 4.1 遍历：

- **std::for_each：** 对容器中的每个元素执行指定操作。
  
  ```cpp
  std::vector<int> vec = {1, 2, 3, 4};
  std::for_each(vec.begin(), vec.end(), [](int& element) {
      // 执行操作，例如打印每个元素
      std::cout << element << " ";
  });
  ```
  
- **std::find：** 在容器中查找指定值的元素。

  ```cpp
  std::vector<int> vec = {1, 2, 3, 4};
  auto it = std::find(vec.begin(), vec.end(), 3);
  if (it != vec.end()) {
      // 找到了值为 3 的元素
  } else {
      // 没有找到值为 3 的元素
  }
  ```


### 4.2 排序和操作：

- **std::sort：** 对容器中的元素进行排序。
  ```cpp
  std::vector<int> vec = {3, 1, 4, 2};
  std::sort(vec.begin(), vec.end()); // 默认升序排序
  ```

- **std::reverse：** 反转容器中的元素顺序。
  ```cpp
  std::vector<int> vec = {1, 2, 3, 4};
  std::reverse(vec.begin(), vec.end()); // 将元素逆序排列
  ```

### 4.3 删除和修改：

- **std::remove：** 从容器中删除指定值的元素。
  ```cpp
  std::vector<int> vec = {1, 2, 3, 2, 4};
  vec.erase(std::remove(vec.begin(), vec.end(), 2), vec.end()); // 删除值为 2 的元素
  ```

- **std::replace：** 将容器中的指定值替换为新值。
  ```cpp
  std::vector<int> vec = {1, 2, 3, 2, 4};
  std::replace(vec.begin(), vec.end(), 2, 5); // 将所有值为 2 的元素替换为 5
  ```

### 4.4 查找和比较：

- **std::max_element / std::min_element：** 查找容器中的最大值和最小值。
  ```cpp
  std::vector<int> vec = {3, 1, 4, 2};
  auto max = std::max_element(vec.begin(), vec.end()); // 查找最大值
  auto min = std::min_element(vec.begin(), vec.end()); // 查找最小值
  ```

- **std::equal：** 检查两个容器是否相等。
  ```cpp
  std::vector<int> vec1 = {1, 2, 3};
  std::vector<int> vec2 = {1, 2, 3};
  bool isEqual = std::equal(vec1.begin(), vec1.end(), vec2.begin());
  ```

这只是 `<algorithm>` 头文件中提供的一小部分方法和函数模板。C++ 标准库中的 `<algorithm>` 包含了更多的算法和函数模板，用于各种操作，包括排序、查找、比较、修改等。

C++ 中的栈（stack）是一种数据结构，遵循后进先出（LIFO）的原则。下面是栈的基本操作：

## 5. 栈的定义：
首先，你需要包含 `<stack>` 头文件。

```cpp
#include <stack>
using namespace std;

stack<int> myStack; // 定义一个存储整数的栈
```

### 5.1 基本操作：

1. **压栈（Push）**：将元素推入栈顶。
   ```cpp
   myStack.push(5); // 将元素 5 推入栈顶
   ```

2. **弹栈（Pop）**：从栈顶移除元素。
   ```cpp
   myStack.pop(); // 弹出栈顶元素
   ```

3. **获取栈顶元素（Top）**：获取栈顶元素的值，不会删除它。
   
   ```cpp
   int topElement = myStack.top(); // 获取栈顶元素的值，但不移除它
   ```
```
   
4. **判断栈是否为空（Empty）**：检查栈是否为空。
   ```cpp
   if (myStack.empty()) {
       // 栈为空
   } else {
       // 栈不为空
   }
```

5. **获取栈的大小（Size）**：获取栈中元素的数量。
   ```cpp
   int stackSize = myStack.size(); // 获取栈中元素的数量
   ```

这些是栈的基本操作，你可以使用这些操作对栈进行数据的推入、弹出以及获取栈顶元素等操作。栈是一种非常有用的数据结构，在许多算法和程序中都有广泛的应用。