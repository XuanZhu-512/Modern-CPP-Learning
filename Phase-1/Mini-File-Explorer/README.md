## **Introduction**
这是一个基于 C++17 <filesystem>库 制作的简易文件管理器，提供了类似 Linux 操作系统管理文件的各种方法

**操作支持**
- `ls`
  
- `cd <dir>`
- `mkdir <name>`
- `rm <name>`
- `search <keyword>`
- `exit`

## **Project Structure**
```
Mini File Explorer/
│
├── include/                 # 头文件
│   └── FileManager.h
│
├── src/                     # 源文件
│   ├── main.cpp
│   └── FileManager.cpp
│
├── build/                   # 编译输出目录
│   └── (所有 .o 和可执行文件在这里生成)
│
├── Makefile                 # 构建脚本
└── README.md                # 项目说明（可选）
```

## **filesystem 库**
`std::filesystem::`
1. `exists(path)`方法接收一个 `path`对象，检查给定路径是否存在于文件系统中
2. `create_directory(foldername)`方法，创建一个文件夹，返回 bool 类型
3. `remove_all(path)`方法接收一个 `path` 对象，删除常规文件、符号链接或者地柜删除目录内所有文件和子目录（返回删除条目数）

<br>

`std::filesystem::path` 对象用于表示文件系统中的路径
1. `string()`方法，将路径以字符串形式返回
2. `filename()`方法，返回表示路径最后一级的 `path` 对象
3. `is_absolute()` / `is_relative()` 方法，判断是否是相对路径 / 绝对路径
4. `<<`运算符重载，直接输出表示路径的字符串
5. `/`运算符重载，`path1 / path2`，若 `path2` 是绝对路径，就覆盖；若为相对路径，就拼接路径

<br>

`std::filesystem::directory_iterator(path)`迭代器遍历给定目录，将每个文件、子目录、符号链接等封装成一个 `std::filesystem::__cxx11::directory_entry` 对象

另外还有 `std::filesystem::recursive_directory_iterator(path)` 迭代器（会递归进入并遍历每一个子文件夹）

1. `is_directory()`方法，判断是否是文件夹
2. `is_regular_file()`方法，判断是否是常规文件
3. `file_size()`方法，返回文件大小（以字节为单位）
4. `path()` 返回完整路径

<br>

`std::filesystem::filesystem_error`对象专门用于表示文件系统操作异常
1. `what()`方法，由 `std::exception`（所有标准异常的基类）提供，返回异常的描述信息，可以直接打印