## **Introduction**
这是一个基于 C++17 及以上的文件缓存管理系统

**Supporting Commands**
- `<load> path`

- `<show> path`
- `status`
- `clear`
- `exit` 


- `CacheManager` 基于 LRU 策略管理缓存池
- `FileLoader` 根据给定路径加载文件内容
- `FileCache` 提供对于缓存文件的一系列操作

**Logic of Source Files**
``` css
┌─────────────┐
│  main.cpp   │
└─────┬───────┘
      │
      ▼
┌─────────────┐       ┌─────────────┐
│ CacheManager│◀──────│  FileCache  │
└─────┬───────┘       └─────────────┘
      │
      ▼
┌─────────────┐
│ FileLoader  │
└─────────────┘
```

## **Project Structure**
```
FileCacheManager/
│
├─ include/
│   ├─ FileCache.h         # 缓存文件对象
│   ├─ CacheManager.h      # 管理缓存池（LRU）
│   └─ FileLoader.h       # 文件读取工具
│
├─ src/
│   ├─ FileCache.cpp
│   ├─ CacheManager.cpp
│   ├─ FileLoader.cpp
│   └─ main.cpp
│
├─ CMakeLists.txt          # 构建文件
└─ README.md
```

## **Usage of STL**
### **filesystem 库**
`std::filesystem::file_tiem_type`
以最高精度和最宽范围可移植地表示文件系统的时间戳。用于获取和设置文件或目录的各种时间属性（如文件的最后修改时间）

1. `std::filesystem::last_write_time(p)` 接收一个路径参数，返回上一次修改时间

<br>

### **chrono 库**
用于处理日期（Date）和时间（Time）的标准库。提供一套类型安全、可移植且高精度的工具，用于测量时间长度（Duration）、表示时间点（Time Point）以及访问系统时钟（Clock）

`std::chrono::system_clock` 
`<chrono>`库提供的一个时钟类型

1. `time_point`成员，是该时钟的一个时间点，用于表示一个具体日期和时间
2. `now()`方法，返回一个 `time_point` 类型变量表示当前时间点

<br>

### **sstream 库**
`std::ostringstream` 允许使用插入运算符来格式化和构建一个字符串，数据并非输出到控制台或文件，而是存储到其内部的 `std::string` 对象中

1. `str()`方法，返回吸入流的数据

<br>

### **fstream 库**
`ifstream` 主要职责是管理数据源头，打开和关闭磁盘上的我呢间，从磁盘读取原始字节并填充到自己的底层缓冲区中，管理流的状态

`std::ifstream file(path, std::ios::in | std::ios::binary)` 同时以输入模式和二进制模式通向指定文件的流对象

1. `rdbuf()`方法（read buffer），在两个流之间进行数据存储

### **mutex 库**
作为一个同步原语保护共享数据。确保在任何时刻，只有一个线程能够访问被其保护的共享数据

`lock_guard`模板类，实现 RAII 模式管理互斥锁。用于简化和安全管理互斥锁，解决手动加锁和解锁带来的两大问题：忘记解锁和异常安全

1. `std::lock_guard<std::mutex> lock(mtx_)`构造函数，接收一个 `mutex` 类型对象。执行此代码时会自动上锁，直到锁被自动释放（离开作用域）