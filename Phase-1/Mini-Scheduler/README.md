## **Introduction**
这是一个 C++17 的定时执行任务的系统，在后台自动、周期性地执行已注册的函数任务

## **Project Structure**
```
Mini-Scheduler/
│
├── include/
│   └── Scheduler.h
│
├── src/
│   └── Scheduler.cpp
│
├── main.cpp
│
└── Makefile
```

## **Usage of STL**

### **functional 库**
`std::function` 是一个通用的多态函数包装器。本质上提供了一个类型擦除机制，使得可以存储不同类型的可调用对象，只要其签名相同
- 通用（General-purpose）：可以存储任何满足特定条件（可调用，CopyConstructible）的东西
- 多态（Polymorphic）：允许使用一个统一的接口来调用不同类型的底层可调用实体

<br>

### **chrono 库**
`std::chrono::system_clock`

1. `to_time_t(time_point)`方法，接收一个 `std::chrono::time_point` 类型变量，转为传统C风格时间戳

### **ctime 库**
`std::ctime(t)`函数，将一个时间戳（`time_t` 类型）转换为一个人类可读的字符串表示